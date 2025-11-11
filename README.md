# 🎓 School Administration System (SAS)

A C++ program that helps administrators analyze student enrollment across Math and Programming classes using set operations.

---

## 🧭 Overview

This system tracks students in two classes and performs set-based analysis to:
- View class rosters
- Identify overlaps and differences
- Count unique and shared students

---

## ✨ Features

| Feature                           | Description                                                                 |
|-----------------------------------|-----------------------------------------------------------------------------|
| 📋 View Class Rosters             | Display students in Math and Programming classes                            |
| 🔗 Union                          | Show all unique students across both classes                                |
| 🎯 Intersection                   | Show students enrolled in both classes                                      |
| ➖ Difference (Math - Programming) | Show students only in Math                                                  |
| ➕ Difference (Programming - Math) | Show students only in Programming                                           |
| 🔢 Count Unique Students          | Display total number of unique students                                     |
| 🔁 Count Common Students          | Display total number of students in both classes                            |

---

## 🛠️ Technologies Used

- **Language**: C++
- **Libraries**: `vector`, `unordered_set`, `set`, `iostream`
- **Structure**: `SAS` class in `SAS.cpp` with interface in `SAS.h`

---

## 🧪 How It Works

1. **Initialize**: Two vectors store student names for Math and Programming.
2. **Analyze**: Use `unordered_set` and `vector` to perform set operations.
3. **Display**: Each operation has a dedicated method with clean output formatting.

---

## ▶️ How to Run

### 1. 📁 File Setup

Make sure you have:
- `SAS.h` — class interface
- `SAS.cpp` — class implementation
- `main.cpp` — driver file to run the program

### 2. 🧱 Compile

```bash
g++ -std=c++11 main.cpp SAS.cpp -o SASApp
