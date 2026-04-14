Perfect 🔥 — you’re asking the *right* question.
Mastering **C++ string functions** (and tricks) gives a *huge edge* in **DSA and Competitive Programming (CP)**.

Below is a **complete, categorized list** of essential string functions, STL methods, tricks, and best practices — everything you need for CP + DSA.

---

## 🧱 1. **String Basics**

```cpp
string s = "hello";
```

| Function                   | Description              | Example            |
| -------------------------- | ------------------------ | ------------------ |
| `s.size()` or `s.length()` | Returns length           | `s.size() -> 5`    |
| `s.empty()`                | Check if string is empty | `if (s.empty())`   |
| `s.clear()`                | Clears string            | `s.clear()`        |
| `s.push_back(ch)`          | Append single char       | `s.push_back('x')` |
| `s.pop_back()`             | Remove last char         | `s.pop_back()`     |
| `s.front()` / `s.back()`   | First / last character   | `s.front() == 'h'` |

🔹 **Tip:** Use `.reserve(n)` to preallocate memory when building large strings (helps avoid TLE due to reallocations).

---

## 🧩 2. **String Construction**

| Operation                   | Example                      | Output       |
| --------------------------- | ---------------------------- | ------------ |
| From char repeated          | `string s(5, 'a');`          | `"aaaaa"`    |
| Substring of another string | `string t = s.substr(1, 3);` | `"ell"`      |
| Concatenate                 | `s + t`                      | `"helloell"` |
| Add char                    | `s += 'x';`                  | `"hellox"`   |

---

## 🔍 3. **Substring Operations**

| Function                     | Description              | Example                    |
| ---------------------------- | ------------------------ | -------------------------- |
| `s.substr(pos, len)`         | Extract substring        | `s.substr(1, 3)` → `"ell"` |
| `s.find(sub)`                | Finds first occurrence   | `s.find("lo") -> 3`        |
| `s.rfind(sub)`               | Last occurrence          | `s.rfind("l") -> 3`        |
| `s.find_first_of(chars)`     | Finds first match of any | `s.find_first_of("aeiou")` |
| `s.find_last_of(chars)`      | Last match               | `s.find_last_of("aeiou")`  |
| `s.find_first_not_of(chars)` | First not matching       |                            |
| `s.find_last_not_of(chars)`  | Last not matching        |                            |

🔹 **Trick:**
For pattern search in CP, prefer **KMP**, **Z-algo**, or **Rabin-Karp** instead of repeated `find()` (O(N²)).

---

## ✂️ 4. **Insertion & Erasure**

| Function                   | Description       | Example                 |
| -------------------------- | ----------------- | ----------------------- |
| `s.insert(pos, str)`       | Insert substring  | `s.insert(2, "abc")`    |
| `s.erase(pos, len)`        | Erase part        | `s.erase(1, 2)`         |
| `s.replace(pos, len, str)` | Replace substring | `s.replace(0, 5, "hi")` |

🔹 **Trick:**
Avoid repeated insertions in middle of large strings — use `ostringstream` or `std::deque<char>` if heavy editing.

---

## ⚖️ 5. **Comparison & Sorting**

| Function                      | Description             | Example                  |
| ----------------------------- | ----------------------- | ------------------------ |
| `s1 == s2`, `<`, `>`          | Lexicographical compare | `"abc" < "abd"` ✅        |
| `s.compare(s2)`               | Returns 0 if equal      | `if (s.compare(t) == 0)` |
| `sort(s.begin(), s.end())`    | Sorts chars             | `"cba"` → `"abc"`        |
| `reverse(s.begin(), s.end())` | Reverses string         | `"abc"` → `"cba"`        |

🔹 **Trick:**
Use `sort` + `unique` for removing duplicates easily.

```cpp
sort(s.begin(), s.end());
s.erase(unique(s.begin(), s.end()), s.end());
```

---

## 🧮 6. **Conversion Utilities**

| Operation          | Function       | Example        |
| ------------------ | -------------- | -------------- |
| String → Int       | `stoi(s)`      | `"123" -> 123` |
| String → Long Long | `stoll(s)`     | `"123456789"`  |
| Int → String       | `to_string(n)` | `123 -> "123"` |
| Char digit → Int   | `ch - '0'`     | `'7' -> 7`     |

🔹 **Trick:**
Always validate input strings (like `"00123"`) when converting in CP — especially for numeric-only strings.

---

## ⚙️ 7. **Transformations**

| Function                                  | Purpose        | Example             |
| ----------------------------------------- | -------------- | ------------------- |
| `transform(all(s), s.begin(), ::tolower)` | To lowercase   | `"HeLLo" → "hello"` |
| `transform(all(s), s.begin(), ::toupper)` | To uppercase   | `"HeLLo" → "HELLO"` |
| `reverse(all(s))`                         | Reverse string | `"abc" → "cba"`     |

🔹 **Shortcut:**
Use macros for clean syntax:

```cpp
#define all(x) x.begin(), x.end()
```

Then:

```cpp
reverse(all(s));
sort(all(s));
```

---

## 🧠 8. **String Stream Tricks**

```cpp
#include <sstream>
stringstream ss("10 20 30");
int a, b, c;
ss >> a >> b >> c; // 10, 20, 30
```

Also:

```cpp
ostringstream out;
out << a << " " << b;
string res = out.str();
```

Useful for:

* Parsing space-separated integers
* Converting between types efficiently

---

## 🧵 9. **Character-level Functions (`<cctype>`)**

| Function                      | Meaning      | Example |
| ----------------------------- | ------------ | ------- |
| `isalpha(ch)`                 | Letter       |         |
| `isdigit(ch)`                 | Digit        |         |
| `isalnum(ch)`                 | Alphanumeric |         |
| `islower(ch)` / `isupper(ch)` | Case check   |         |
| `tolower(ch)` / `toupper(ch)` | Case convert |         |

---

## ⚡ 10. **Advanced & CP Tricks**

### 🔸 a) Prefix Hashing (for substring equality)

Used in substring comparison problems:

```cpp
const long long base = 131, mod = 1e9+7;
vector<long long> h(n+1), p(n+1, 1);
for (int i=0; i<n; ++i){
    h[i+1] = (h[i]*base + s[i]) % mod;
    p[i+1] = (p[i]*base) % mod;
}
auto get_hash = [&](int l, int r){
    return (h[r] - h[l]*p[r-l]%mod + mod)%mod;
};
```

### 🔸 b) Z-Algorithm / KMP / Rolling Hash

Used for pattern search or prefix-suffix matching efficiently.

### 🔸 c) Custom Sorting by String Rules

Example: Sort by length, then lexicographically

```cpp
sort(v.begin(), v.end(), [](string &a, string &b){
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
});
```

---

## 🪄 11. **Common CP Shortcuts**

| Task                  | Trick                                       |
| --------------------- | ------------------------------------------- |
| Reverse string        | `reverse(all(s));`                          |
| Remove char           | `s.erase(remove(all(s), 'a'), s.end());`    |
| Count char            | `count(all(s), 'a')`                        |
| Join vector of chars  | `string s(v.begin(), v.end());`             |
| Check palindrome      | `s == string(s.rbegin(), s.rend())`         |
| Split string (manual) | use `stringstream` or loop with `find(' ')` |

---

## 🚀 12. **Performance & Optimization Tips**

✅ Prefer **`reserve()`** for big string concatenation.
✅ Avoid repeated `+` concatenations in loops → use `ostringstream` or `string builder`.
✅ Use `std::string_view` for substring-heavy problems (C++17).
✅ `find()` and `substr()` are **O(N)** — don’t use inside nested loops.
✅ When sorting many strings, store as references or indices to avoid copy cost.

---

Would you like me to give you a **cheat sheet PDF** (with categorized examples + quick syntax + CP tricks)**?**
I can generate it for you (ready for VS Code or notes).
