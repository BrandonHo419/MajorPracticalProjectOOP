#!/usr/bin/bash

# This is a bash file that automatically executes commands on the Linux Terminal Window for requesting weather

location="$1"
temperature=$(curl -s "wttr.in/$location?format=%t")  # Get the temperature
rainfall=$(curl -s "wttr.in/$location?format=%p")  # Get precipitation

# Check if temperature or rainfall are empty, and set defaults if necessary
if [ -z "$temperature" ]; then
  temperature="20°C"
fi

if [ -z "$rainfall" ]; then
  rainfall="0.0mm"
fi

# Print the results
echo "$temperature"
echo "$rainfall"
