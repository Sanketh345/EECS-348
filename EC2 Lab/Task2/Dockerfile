# Set the base image to use
FROM gcc:latest
# Copy the C program into the container
COPY task2.c .
# Compile the C program
RUN gcc -o task2 task2.c
# Set the command to run when the container starts
CMD ["./task2"]