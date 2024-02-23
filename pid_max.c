#!/bin/bash

# Script: max_pid.sh
# Author: [Your Name]
# Date: [Date]
# Description: This script prints the maximum value a process ID (PID) can be.

# Retrieve the maximum PID value from the system configuration
max_pid=$(cat /proc/sys/kernel/pid_max)

# Print the maximum PID value to the terminal
echo "Maximum PID value: $max_pid"
