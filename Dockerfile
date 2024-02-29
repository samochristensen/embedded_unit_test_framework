# Use a base image with GCC ARM embedded toolchain
FROM debian:latest

# Install dependencies
RUN apt-get update && apt-get install -y \
    cmake \
    make \
    gcc-arm-none-eabi \
    git \
    && rm -rf /var/lib/apt/lists/*

# Set the working directory in the container
# WORKDIR /usr/src/app

# Command to build your project
# Replace with your specific build commands
# CMD ["make", "all"]
