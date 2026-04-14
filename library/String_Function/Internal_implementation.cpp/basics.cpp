#include <string>
#include <iostream>
#include <cstring>
#include <stdexcept>
#include <algorithm>

using namespace std;

class basic_string_ {
private:
    // SSO (small string optimization) union
    union {
        struct {
            char* _ptr;
            size_t _size;
            size_t _capacity;
        } _long_string;

        struct {
            char _buffer[16];
            unsigned char _sso_size : 7;
            unsigned char _is_sso : 1;
        } _short_string;
    };

    // Helper methods
    bool _is_sso() const noexcept {
        return _short_string._is_sso;
    }

    char* _get_data() noexcept {
        return _is_sso() ? _short_string._buffer : _long_string._ptr;
    }

    const char* _get_data() const noexcept {
        return _is_sso() ? _short_string._buffer : _long_string._ptr;
    }

    size_t _get_size() const noexcept {
        return _is_sso() ? _short_string._sso_size : _long_string._size;
    }

    size_t _get_capacity() const noexcept {
        return _is_sso() ? sizeof(_short_string._buffer) - 1 : _long_string._capacity;
    }

    void _set_size(size_t new_size) noexcept {
        if (_is_sso()) {
            _short_string._sso_size = static_cast<unsigned char>(new_size);
        } else {
            _long_string._size = new_size;
        }
    }

    void _set_capacity(size_t new_capacity) noexcept {
        if (!_is_sso()) {
            _long_string._capacity = new_capacity;
        }
    }

    void _init_sso() noexcept {
        _short_string._is_sso = 1;
        _short_string._sso_size = 0;
        _short_string._buffer[0] = '\0';
    }

    void _init_long_string(size_t capacity) {
        _long_string._ptr = new char[capacity + 1];
        _long_string._size = 0;
        _long_string._capacity = capacity;
        _long_string._ptr[0] = '\0';
        _short_string._is_sso = 0;
    }

    void _reallocate(size_t new_capacity) {
        if (new_capacity <= sizeof(_short_string._buffer) - 1) {
            // Switch to SSO
            if (!_is_sso()) {
                char* old_ptr = _long_string._ptr;
                size_t old_size = _long_string._size;
                
                _init_sso();
                if (old_ptr) {
                    memcpy(_short_string._buffer, old_ptr, min(old_size, sizeof(_short_string._buffer) - 1));
                    _short_string._sso_size = static_cast<unsigned char>(old_size);
                    _short_string._buffer[old_size] = '\0';
                    delete[] old_ptr;
                }
            }
        } else {
            // Switch to or resize heap allocation
            if (_is_sso()) {
                // SSO to heap
                char temp[sizeof(_short_string._buffer)];
                memcpy(temp, _short_string._buffer, sizeof(_short_string._buffer));
                
                _init_long_string(new_capacity);
                memcpy(_long_string._ptr, temp, _short_string._sso_size);
                _long_string._size = _short_string._sso_size;
                _long_string._ptr[_long_string._size] = '\0';
            } else {
                // Resize heap allocation
                char* new_ptr = new char[new_capacity + 1];
                if (_long_string._ptr) {
                    memcpy(new_ptr, _long_string._ptr, min(_long_string._size, new_capacity));
                    delete[] _long_string._ptr;
                }
                _long_string._ptr = new_ptr;
                _long_string._capacity = new_capacity;
                if (_long_string._size > new_capacity) {
                    _long_string._size = new_capacity;
                }
                _long_string._ptr[_long_string._size] = '\0';
            }
        }
    }

public:
    // Constructors
    basic_string_() noexcept {
        _init_sso();
    }

    basic_string_(const char* str) {
        size_t len = strlen(str);
        if (len <= sizeof(_short_string._buffer) - 1) {
            _init_sso();
            memcpy(_short_string._buffer, str, len);
            _short_string._sso_size = static_cast<unsigned char>(len);
            _short_string._buffer[len] = '\0';
        } else {
            _init_long_string(len);
            memcpy(_long_string._ptr, str, len);
            _long_string._size = len;
            _long_string._ptr[len] = '\0';
        }
    }

    basic_string_(const basic_string_& other) {
        if (other._is_sso()) {
            memcpy(&_short_string, &other._short_string, sizeof(_short_string));
        } else {
            _init_long_string(other._long_string._capacity);
            memcpy(_long_string._ptr, other._long_string._ptr, other._long_string._size);
            _long_string._size = other._long_string._size;
            _long_string._ptr[_long_string._size] = '\0';
        }
    }

    basic_string_(basic_string_&& other) noexcept {
        if (other._is_sso()) {
            memcpy(&_short_string, &other._short_string, sizeof(_short_string));
            other._init_sso(); // Reset source
        } else {
            _long_string._ptr = other._long_string._ptr;
            _long_string._size = other._long_string._size;
            _long_string._capacity = other._long_string._capacity;
            _short_string._is_sso = 0;
            
            // Reset source
            other._init_sso();
        }
    }

    // Destructor
    ~basic_string_() {
        if (!_is_sso() && _long_string._ptr) {
            delete[] _long_string._ptr;
        }
    }

    // Assignment operators
    basic_string_& operator=(const basic_string_& other) {
        if (this != &other) {
            clear();
            if (other._is_sso()) {
                memcpy(&_short_string, &other._short_string, sizeof(_short_string));
            } else {
                _reallocate(other._long_string._capacity);
                memcpy(_get_data(), other._get_data(), other.size());
                _set_size(other.size());
                _get_data()[other.size()] = '\0';
            }
        }
        return *this;
    }

    basic_string_& operator=(basic_string_&& other) noexcept {
        if (this != &other) {
            if (!_is_sso() && _long_string._ptr) {
                delete[] _long_string._ptr;
            }
            
            if (other._is_sso()) {
                memcpy(&_short_string, &other._short_string, sizeof(_short_string));
                other._init_sso();
            } else {
                _long_string._ptr = other._long_string._ptr;
                _long_string._size = other._long_string._size;
                _long_string._capacity = other._long_string._capacity;
                _short_string._is_sso = 0;
                other._init_sso();
            }
        }
        return *this;
    }

    // size() / length()
    size_t size() const noexcept {
        return _get_size();
    }
    
    size_t length() const noexcept {
        return size();
    }

    // empty()
    bool empty() const noexcept {
        return size() == 0;
    }

    // clear()
    void clear() noexcept {
        if (_is_sso()) {
            _short_string._sso_size = 0;
            _short_string._buffer[0] = '\0';
        } else {
            _long_string._size = 0;
            _long_string._ptr[0] = '\0';
        }
    }

    // capacity()
    size_t capacity() const noexcept {
        return _get_capacity();
    }

    // reserve()
    void reserve(size_t new_capacity) {
        if (new_capacity > _get_capacity()) {
            _reallocate(new_capacity);
        }
    }

    // shrink_to_fit()
    void shrink_to_fit() {
        size_t current_size = size();
        if (!_is_sso() && current_size < _long_string._capacity) {
            if (current_size <= sizeof(_short_string._buffer) - 1) {
                // Switch to SSO
                char* old_ptr = _long_string._ptr;
                memcpy(_short_string._buffer, old_ptr, current_size);
                _short_string._sso_size = static_cast<unsigned char>(current_size);
                _short_string._buffer[current_size] = '\0';
                _short_string._is_sso = 1;
                delete[] old_ptr;
            } else {
                // Reallocate to exact size
                _reallocate(current_size);
            }
        }
    }

    // push_back()
    void push_back(char c) {
        size_t current_size = size();
        size_t current_capacity = capacity();
        
        if (current_size + 1 > current_capacity) {
            _reallocate(max(current_capacity * 2, size_t(16)));
        }
        
        _get_data()[current_size] = c;
        _set_size(current_size + 1);
        _get_data()[current_size + 1] = '\0';
    }

    // pop_back()
    void pop_back() {
        size_t current_size = size();
        if (current_size == 0) {
            return;
        }
        
        _set_size(current_size - 1);
        _get_data()[current_size - 1] = '\0';
    }

    // front()
    char& front() {
        if (empty()) {
            throw std::out_of_range("basic_string_::front(): string is empty");
        }
        return _get_data()[0];
    }

    const char& front() const {
        if (empty()) {
            throw std::out_of_range("basic_string_::front(): string is empty");
        }
        return _get_data()[0];
    }

    // back()
    char& back() {
        if (empty()) {
            throw std::out_of_range("basic_string_::back(): string is empty");
        }
        return _get_data()[size() - 1];
    }

    const char& back() const {
        if (empty()) {
            throw std::out_of_range("basic_string_::back(): string is empty");
        }
        return _get_data()[size() - 1];
    }

    // at()
    char& at(size_t pos) {
        if (pos >= size()) {
            throw std::out_of_range("basic_string_::at(): position out of range");
        }
        return _get_data()[pos];
    }

    const char& at(size_t pos) const {
        if (pos >= size()) {
            throw std::out_of_range("basic_string_::at(): position out of range");
        }
        return _get_data()[pos];
    }

    // operator[]
    char& operator[](size_t pos) {
        return _get_data()[pos];
    }

    const char& operator[](size_t pos) const {
        return _get_data()[pos];
    }

    // c_str()
    const char* c_str() const noexcept {
        return _get_data();
    }

    // data()
    char* data() noexcept {
        return _get_data();
    }

    const char* data() const noexcept {
        return _get_data();
    }

    // append()
    basic_string_& append(const char* str) {
        size_t append_len = strlen(str);
        size_t current_size = size();
        size_t new_size = current_size + append_len;
        
        if (new_size > capacity()) {
            _reallocate(max(capacity() * 2, new_size));
        }
        
        memcpy(_get_data() + current_size, str, append_len);
        _set_size(new_size);
        _get_data()[new_size] = '\0';
        
        return *this;
    }

    basic_string_& append(const basic_string_& str) {
        return append(str.c_str());
    }

    // operator+=
    basic_string_& operator+=(const char* str) {
        return append(str);
    }

    basic_string_& operator+=(const basic_string_& str) {
        return append(str);
    }

    basic_string_& operator+=(char c) {
        push_back(c);
        return *this;
    }

    // compare()
    int compare(const basic_string_& other) const noexcept {
        return strcmp(c_str(), other.c_str());
    }

    int compare(const char* str) const noexcept {
        return strcmp(c_str(), str);
    }

    // find()
    size_t find(char c, size_t pos = 0) const noexcept {
        if (pos >= size()) return npos;
        const char* result = strchr(_get_data() + pos, c);
        return result ? result - _get_data() : npos;
    }

    size_t find(const char* str, size_t pos = 0) const noexcept {
        if (pos >= size()) return npos;
        const char* result = strstr(_get_data() + pos, str);
        return result ? result - _get_data() : npos;
    }

    size_t find(const basic_string_& str, size_t pos = 0) const noexcept {
        return find(str.c_str(), pos);
    }

    // substr()
    basic_string_ substr(size_t pos = 0, size_t count = npos) const {
        if (pos > size()) {
            throw std::out_of_range("basic_string_::substr(): position out of range");
        }
        
        size_t actual_count = min(count, size() - pos);
        return basic_string_(_get_data() + pos, actual_count);
    }

    // Static member
    static const size_t npos = -1;

private:
    // Private constructor for substr
    basic_string_(const char* str, size_t count) {
        if (count <= sizeof(_short_string._buffer) - 1) {
            _init_sso();
            memcpy(_short_string._buffer, str, count);
            _short_string._sso_size = static_cast<unsigned char>(count);
            _short_string._buffer[count] = '\0';
        } else {
            _init_long_string(count);
            memcpy(_long_string._ptr, str, count);
            _long_string._size = count;
            _long_string._ptr[count] = '\0';
        }
    }
};

// Non-member functions
basic_string_ operator+(const basic_string_& lhs, const basic_string_& rhs) {
    basic_string_ result = lhs;
    result += rhs;
    return result;
}

basic_string_ operator+(const basic_string_& lhs, const char* rhs) {
    basic_string_ result = lhs;
    result += rhs;
    return result;
}

basic_string_ operator+(const char* lhs, const basic_string_& rhs) {
    basic_string_ result = lhs;
    result += rhs;
    return result;
}

bool operator==(const basic_string_& lhs, const basic_string_& rhs) {
    return lhs.compare(rhs) == 0;
}

bool operator!=(const basic_string_& lhs, const basic_string_& rhs) {
    return lhs.compare(rhs) != 0;
}

bool operator<(const basic_string_& lhs, const basic_string_& rhs) {
    return lhs.compare(rhs) < 0;
}

bool operator>(const basic_string_& lhs, const basic_string_& rhs) {
    return lhs.compare(rhs) > 0;
}

bool operator<=(const basic_string_& lhs, const basic_string_& rhs) {
    return lhs.compare(rhs) <= 0;
}

bool operator>=(const basic_string_& lhs, const basic_string_& rhs) {
    return lhs.compare(rhs) >= 0;
}

// Output stream operator
std::ostream& operator<<(std::ostream& os, const basic_string_& str) {
    return os << str.c_str();
}

int main() {
    // Test all functions
    cout << "=== Testing basic_string_ class ===" << endl;

    // Constructors
    basic_string_ s1;
    cout << "Default constructor: '" << s1 << "' size: " << s1.size() << " empty: " << s1.empty() << endl;

    basic_string_ s2 = "Hello";
    cout << "C-string constructor: '" << s2 << "' size: " << s2.size() << " capacity: " << s2.capacity() << endl;

    basic_string_ s3 = s2;
    cout << "Copy constructor: '" << s3 << "' size: " << s3.size() << endl;

    // Assignment
    s1 = "World";
    cout << "Assignment: '" << s1 << "'" << endl;

    // Size/length/empty
    cout << "s2 size: " << s2.size() << ", length: " << s2.length() << ", empty: " << s2.empty() << endl;

    // Clear
    s3.clear();
    cout << "After clear: '" << s3 << "' size: " << s3.size() << " empty: " << s3.empty() << endl;

    // Push back
    basic_string_ s4 = "Hel";
    s4.push_back('l');
    s4.push_back('o');
    cout << "After push_back: '" << s4 << "'" << endl;

    // Pop back
    s4.pop_back();
    cout << "After pop_back: '" << s4 << "'" << endl;

    // Front/back
    basic_string_ s5 = "Hello";
    cout << "Front: '" << s5.front() << "', Back: '" << s5.back() << "'" << endl;

    // At and operator[]
    cout << "s5[0]: '" << s5[0] << "', s5.at(1): '" << s5.at(1) << "'" << endl;

    // Append and +=
    basic_string_ s6 = "Hello";
    s6.append(" World");
    cout << "After append: '" << s6 << "'" << endl;

    s6 += "!";
    cout << "After +=: '" << s6 << "'" << endl;

    // Find
    size_t pos = s6.find('W');
    cout << "Find 'W' in '" << s6 << "': " << pos << endl;

    pos = s6.find("World");
    cout << "Find 'World' in '" << s6 << "': " << pos << endl;

    // Substring
    basic_string_ s7 = s6.substr(6, 5);
    cout << "Substring(6,5): '" << s7 << "'" << endl;

    // Compare
    basic_string_ s8 = "abc";
    basic_string_ s9 = "abd";
    cout << "Compare 'abc' with 'abd': " << s8.compare(s9) << endl;

    // Reserve and capacity
    basic_string_ s10;
    s10.reserve(100);
    cout << "After reserve(100): capacity: " << s10.capacity() << endl;

    // Operator+
    basic_string_ s11 = "Hello" + basic_string_(" World");
    cout << "Operator+: '" << s11 << "'" << endl;

    // Comparison operators
    cout << "Equality: 'Hello' == 'Hello': " << (basic_string_("Hello") == basic_string_("Hello")) << endl;
    cout << "Inequality: 'Hello' != 'World': " << (basic_string_("Hello") != basic_string_("World")) << endl;

    // SSO vs Heap allocation test
    basic_string_ short_str = "Short";
    basic_string_ long_str = "This is a very long string that should trigger heap allocation";
    
    cout << "\nSSO/Heap test:" << endl;
    cout << "Short string '" << short_str << "' - SSO: likely" << endl;
    cout << "Long string '" << long_str << "' - SSO: unlikely, capacity: " << long_str.capacity() << endl;

    return 0;
}