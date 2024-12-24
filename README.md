# Philosophers

This project implements the classic Dining Philosophers problem using threads and mutexes in C. The program simulates philosophers sitting at a round table, alternating between eating, thinking, and sleeping while sharing forks with their neighbors.
<p align="center">
  <img src="https://raw.githubusercontent.com/anasooo/Philosophers/refs/heads/main/philo/img/p.webp?token=GHSAT0AAAAAAC2GLQX2VJVFK37BU7AKWSJSZ3KA7QQ" alt="Philosophers Dining Problem" width="600">
</p>

## Problem Description

The simulation follows these rules:
- Philosophers sit at a round table with a large bowl of spaghetti in the center
- Each philosopher needs two forks to eat (one from their left and one from their right)
- Philosophers alternate between three states:
  - Eating (requires both forks)
  - Sleeping (after finishing eating)
  - Thinking (after waking up)
- The simulation continues until either:
  - A philosopher dies of starvation
  - All philosophers have eaten the required number of times (if specified)

## Usage

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

### Example

```bash
./philo 5 800 200 200 5
```

## Implementation Details

### Core Features
- Each philosopher is represented by a thread
- Forks are protected by mutexes
- No global variables
- Death detection within 10ms of actual death

### Output Format
The program logs state changes in the following format:
```
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
```
Where:
- `timestamp_in_ms` is the current time in milliseconds
- `X` is the philosopher's number (1 to number_of_philosophers)



## Building

```bash
make        # Build the program
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Rebuild the program
```

## Error Handling

The program includes robust error handling for:
- Invalid arguments
- Thread creation failures
- Mutex initialization failures
- Memory allocation failures
