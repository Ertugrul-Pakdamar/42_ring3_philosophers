# Terminology and Function Documentation

> This file is for explaining every functions and their return values.

## Validation Functions

### `int ft_is_argv_valid(int argc, char **argv)`

- Returns `1` if the arguments are valid.
- Returns `0` if the arguments are invalid.

### `static int ft_is_args_numable(char **argv)`

- Returns `1` if all arguments are valid.
- Returns `0` if any argument is invalid.

## Custom Library Functions

### `int ft_custom_atoi(char *str, int *num)`

- Returns `1` if the conversion is successful.
- Returns `0` if the conversion fails.
- Sets `*num` to the converted integer value.

### `int ft_isdigit(int c)`

- Returns `1` if `c` is a digit (0-9).
- Returns `0` if `c` is not a digit.

## Initialization Functions

### `void ft_init_args(t_data *data, char **argv)`

- sets t_data structure with the values from `argv`.

### `void ft_init_philos(t_data *data)`

- Initializes the `t_philo **philos` data in the `t_data` structure.

## Exit Functions

### `void ft_exit_prog(t_data *data, int exit_code)`

- Cleans up `t_data *data` and exits the program with the given exit code.
