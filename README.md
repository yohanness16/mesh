# Single Node Project

A minimal C project structured around a single node representation with build and test support.

## Project Structure

```
.
├── Makefile
├── README.md
├── .gitignore
├── src/
│   ├── main.c
│   ├── node.c
│   └── node.h
└── tests/
    └── test_node.c
```

## Getting Started

### Prerequisites

- GCC or Clang (C11 support)
- GNU Make

### Building the Project

Compile the main executable:
```bash
make
```

### Running the Application

Execute the application:
```bash
make run
# or
./node_app
```

### Running Tests

Execute the unit tests:
```bash
make test
```

### Cleaning Up

Remove generated binaries and object files:
```bash
make clean
```
