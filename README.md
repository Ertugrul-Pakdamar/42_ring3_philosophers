# 🍽️ Philosophers

![C](https://img.shields.io/badge/C-blue?style=for-the-badge&logo=C&logoColor=blue&labelColor=white)
![Threading](https://img.shields.io/badge/Threading-green?style=for-the-badge&logo=GNU&logoColor=green&labelColor=white)
![Mutex](https://img.shields.io/badge/Mutex-red?style=for-the-badge&logo=GNU&logoColor=red&labelColor=white)
![42](https://img.shields.io/badge/42-000000?style=for-the-badge&logo=42&logoColor=white)

> _A threading and synchronization project that simulates the classic dining philosophers problem_

## 📋 Table of Contents

- [About](#about)
- [The Problem](#the-problem)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Arguments](#arguments)
- [Algorithm](#algorithm)
- [Key Concepts](#key-concepts)
- [Project Structure](#project-structure)
- [Contributing](#contributing)
- [Author](#author)

## 🧠 About

The **Philosophers** project is a classic computer science problem that demonstrates the challenges of resource sharing in concurrent programming. This implementation uses **pthreads** and **mutexes** to solve synchronization issues while avoiding deadlocks and race conditions.

This project is part of the **42 School curriculum** and focuses on:

- Multi-threading programming
- Mutex synchronization
- Resource management
- Deadlock prevention
- Race condition handling

## 🤔 The Problem

_One or more philosophers sit at a round table. There is a large bowl of spaghetti in the middle of the table. The philosophers alternatively eat, think, or sleep. While they are eating, they are not thinking nor sleeping; while thinking, they are not eating nor sleeping; and, of course, while sleeping, they are not eating nor thinking._

**The Challenge:**

- Each philosopher needs **two forks** to eat
- There are only **N forks** for **N philosophers**
- Philosophers must **share forks** with their neighbors
- **No philosopher should starve**
- **Avoid deadlocks** at all costs

## ✨ Features

- 🔄 **Multi-threaded simulation** with precise timing
- 🔒 **Mutex-based synchronization** for fork management
- ⚡ **Deadlock prevention** through careful resource ordering
- 📊 **Real-time status monitoring** of each philosopher
- 🎯 **Configurable parameters** for different scenarios
- 🛡️ **Memory leak protection** and proper cleanup
- ⏱️ **Microsecond precision** timing system

## 🚀 Installation

```bash
# Clone the repository
git clone https://github.com/Ertugrul-Pakdamar/42_ring3_philosophers.git

# Navigate to the project directory
cd 42_ring3_philosophers/philo

# Compile the project
make

# Clean object files (optional)
make clean
```

## 💻 Usage

```bash
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
```

### Examples

```bash
# Basic simulation with 5 philosophers
./philo 5 800 200 200

# Simulation with meal limit
./philo 4 410 200 200 10

# Large scale simulation
./philo 100 800 200 200 50

# Quick death scenario (for testing)
./philo 4 310 200 100
```

## 📊 Arguments

| Argument                                    | Description                                                       | Unit         | Required |
| ------------------------------------------- | ----------------------------------------------------------------- | ------------ | -------- |
| `number_of_philosophers`                    | Number of philosophers and forks                                  | count        | ✅       |
| `time_to_die`                               | Time before a philosopher dies without eating                     | milliseconds | ✅       |
| `time_to_eat`                               | Time it takes for a philosopher to eat                            | milliseconds | ✅       |
| `time_to_sleep`                             | Time a philosopher spends sleeping                                | milliseconds | ✅       |
| `number_of_times_each_philosopher_must_eat` | Simulation stops when all philosophers have eaten this many times | count        | ❌       |

## 🧮 Algorithm

### Core Logic

1. **Initialization Phase**

   - Create philosopher threads
   - Initialize mutexes for each fork
   - Set up shared data structures

2. **Life Cycle**

   ```
   THINK → GRAB FORKS → EAT → RELEASE FORKS → SLEEP → REPEAT
   ```

3. **Deadlock Prevention**

   - Philosophers with **odd IDs** grab **left fork first**
   - Philosophers with **even IDs** grab **right fork first**
   - This prevents circular wait conditions

4. **Death Detection**
   - Separate monitoring thread checks each philosopher's last meal time
   - Immediate termination when death is detected

### Synchronization Strategy

```c
// Fork acquisition order prevents deadlocks
if (philo->id % 2 == 0) {
    pthread_mutex_lock(&right_fork);
    pthread_mutex_lock(&left_fork);
} else {
    pthread_mutex_lock(&left_fork);
    pthread_mutex_lock(&right_fork);
}
```

## 🔑 Key Concepts

### Threading Concepts Used

- **pthreads**: POSIX threads for concurrent execution
- **Mutex locks**: Mutual exclusion for shared resources
- **Thread synchronization**: Coordinating access to shared data
- **Race condition prevention**: Ensuring data consistency

### Design Patterns

- **Producer-Consumer**: Philosophers consume forks and produce availability
- **Monitor Pattern**: Centralized state management with mutexes
- **Resource Ordering**: Preventing deadlocks through consistent lock ordering

## 📁 Project Structure

```
philo/
├── ft_main.c                    # Entry point and program flow
├── Makefile                     # Build configuration
├── includes/
│   └── ft_philo.h              # Header file with structures and prototypes
└── srcs/
    ├── ft_exit_prog.c          # Clean exit and memory management
    ├── ft_print_status.c       # Thread-safe status printing
    ├── ft_validations.c        # Input validation and error handling
    ├── initializations/
    │   ├── ft_init_args.c      # Argument parsing and data initialization
    │   └── ft_init_philos.c    # Philosopher structure initialization
    ├── life_cycle/
    │   ├── ft_death_thread.c   # Death monitoring thread
    │   ├── ft_life_cycle_helpers.c # Life cycle utility functions
    │   ├── ft_life_cycle.c     # Main philosopher routine
    │   └── ft_unlock_forks.c   # Fork release management
    ├── threads/
    │   ├── ft_close_threads.c  # Thread cleanup and joining
    │   └── ft_create_threads.c # Thread creation and initialization
    └── utils/
        ├── ft_custom_atoi.c    # Custom string to integer conversion
        ├── ft_get.c            # Thread-safe getters for shared data
        ├── ft_isdigit.c        # Character validation utility
        └── ft_usleep.c         # Precise timing utility
```

## 🧪 Testing Scenarios

### Recommended Test Cases

```bash
# No one should die
./philo 5 800 200 200

# No one should die with meal limit
./philo 5 800 200 200 7

# One philosopher should die
./philo 1 800 200 200

# Edge case: tight timing
./philo 4 410 200 200

# Stress test: many philosophers
./philo 200 800 200 200
```

### Expected Outputs

```
[timestamp] 1 has taken a fork
[timestamp] 1 is eating
[timestamp] 1 is sleeping
[timestamp] 1 is thinking
[timestamp] 2 has taken a fork
...
```

## 🔧 Development Notes

### Compilation Flags

- `-Wall -Wextra -Werror`: Strict error checking
- `-pthread`: Enable pthread support

### Memory Management

- All dynamically allocated memory is properly freed
- Mutex destruction on program termination
- No memory leaks according to Valgrind

### Performance Considerations

- Optimized for minimal CPU usage
- Precise timing without busy waiting
- Efficient mutex usage patterns

## 🤝 Contributing

1. **Fork** the project
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. **Commit** your changes (`git commit -m 'Add some AmazingFeature'`)
4. **Push** to the branch (`git push origin feature/AmazingFeature`)
5. Open a **Pull Request**

## 📧 Author

**Ertuğrul Pakdamar**

- 🎓 42 İstanbul Student
- 🌐 [GitHub](https://github.com/Ertugrul-Pakdamar)
- 💼 [LinkedIn](https://www.linkedin.com/in/ertuğrul-pakdamar/)
- 📧 epakdama@student.42istanbul.com.tr

---

<div align="center">

**Made with ❤️ at 42 İstanbul**

_This project is part of the 42 School curriculum_

[![42](https://img.shields.io/badge/42-000000?style=flat&logo=42&logoColor=white)](https://42istanbul.com.tr/)

</div>
