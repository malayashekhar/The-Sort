
# The Sort

## Overview
**The Sort** is a graphical simulation software of various sorting algorithms implemented in C++ using the SFML library. It visually demonstrates how different sorting algorithms work.
This project is designed to help users understand the inner workings of these algorithms through interactive and visual representation.

## Preview

![bubblesort](https://github.com/user-attachments/assets/fe2e28db-1f8a-4220-835d-2bffb17162b4)
![insertionsort](https://github.com/user-attachments/assets/fdbcc4e6-7c8d-442b-8265-bdfcb165b7fd)
![selectionsort](https://github.com/user-attachments/assets/1b5ea112-b880-406e-84e5-34d7e43d8249)
![radixsort](https://github.com/user-attachments/assets/3f90b232-2f2f-4e43-888a-644f48a5a964)
![mergesort](https://github.com/user-attachments/assets/e06a3bef-8582-4b22-9fd1-bd6dc0eabf82)
![quicksort](https://github.com/user-attachments/assets/9bf3edd6-273b-4540-9bf1-46820d1bc055)


## Features
- **Graphical Visualization:** Watch sorting algorithms in action with clear and colorful visualizations.
- **Multiple Algorithms:** Includes Bubble Sort, Insertion Sort, Selection Sort, Radix Sort, Merge Sort, and Quick Sort.
- **Interactive Controls:** Select, Generate, Shuffle and Start the simulation.
- **Step-by-Step Execution:** View the sorting process step-by-step for detailed understanding.

## Requirements
- C++ Compiler (g++ recommended)
- SFML Library

## Installation

1. **Clone the repository:**
    ```sh
    git clone https://github.com/malayashekhar/TheSort.git
    cd TheSort
    ```

2. **Install SFML:**
    - **On macOS:**
        ```sh
        brew install sfml
        ```
    - **On Windows:**
        - Download the SFML library from the [official website](https://www.sfml-dev.org/download.php).
        - Follow the [tutorial](https://www.sfml-dev.org/tutorials/2.5/start-vc.php) for setting up SFML with your compiler.

3. **Build the project:**
    ```sh
    mkdir build
    cd build
    cmake ..
    make
    ```

## Usage
1. **Run the executable:**
    ```sh
    ./TheSort
    ```

2. **Controls:**
    - `Enter`: Start the sorting process.
    - `1`: Select Bubble Sort.
    - `2`: Select Insertion Sort.
    - `3`: Select Selection Sort.
    - `4`: Select Radix Sort.
    - `5`: Select Merge Sort.
    - `6`: Select Quick Sort.
    - `S`: Shuffle.
    - `R`: Random generate.


## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
