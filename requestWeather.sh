#!/usr/bin/bash

# This is a bash file that automatically executes commands on the Linux Terminal Window for requesting weather

location="$1"
weather=$(curl -s "wttr.in/$location?format=%C")  # Get the condition (e.g., sunny, cloudy)
temperature=$(curl -s "wttr.in/$location?format=%t")  # Get the temperature
rainfall=$(curl -s "wttr.in/$location?format=%p")  # Get precipitation

# Print the results
echo "$weather"
echo "$temperature"
echo "$rainfall"
