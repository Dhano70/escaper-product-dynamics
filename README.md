# Escaper-product-dynamics
This a Product Dynamics project and describes the software for an autonomous “escaper” robot. The robot drives independently, measures its speed using encoders, controls it with a PID controller, and avoids obstacles using an ultrasonic distance sensor. Using an Arduino UNO as the brain.

## 📂 Project Structure

This project follows the standard PlatformIO directory structure:

* **`include/`**: Header files (`.h`). This is where the "blueprints" (class definitions and constants) live.
    * `robot_config.h`: Pin definitions and physical robot constants.
    * `pid_controller.h`: Logic for the PID calculation engine.
    * `motor_control.h`: Interface for the Cytron motor drivers.
* **`src/`**: Source files (`.cpp`). The actual "meat" of the code.
    * `main.cpp`: The main state machine and Arduino `setup/loop`.
    * `pid_controller.cpp`: PID mathematical implementation.
    * `motor_control.cpp`: Motor movement logic.
* **`lib/`**: Third-party libraries (if not managed via platformio.ini).
* **`platformio.ini`**: The configuration file that tells VS Code which board (Arduino Uno) and libraries to use.
