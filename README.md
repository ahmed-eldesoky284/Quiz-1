# Arduino 2WDRobot with Keypad and LCD I2C

![Access Control System](https://github.com/ahmed-eldesoky284/Quiz-1/blob/main/Capture1.png)

## Requirements

To replicate or modify this project, you will need the following components:

- 2 Arduino Uno
- Keypad (4x4)
- 2 LCD I2C (16,2)
- 2WD Motor
- Motor Drive L293D


## Installation

1. Clone this repository to your local machine:

   ```bash
   git clone https://github.com/ahmed-eldesoky284/Quiz1.git
   ```

2. Connect the Arduino board to your computer using a USB cable.

3. Connect the keypad and LCD and MotorDrive to the Arduino board as per the circuit diagram provided in the repository.

4. Open the Arduino IDE (Integrated Development Environment) on your computer.

5. In the Arduino IDE, go to **File** > **Open** and navigate to the cloned repository folder. Open the `Quiz1.ino` file.

6. Make sure you have the required libraries installed. If not, install them by going to **Sketch** > **Include Library** > **Manage Libraries** and search for the following libraries:

   - `Keypad` (for keypad)
   - 'LiquidCrystal_I2C'(for LCD)

7. Select the appropriate Arduino board and port from the **Tools** menu.

8. Compile and upload the code to the Arduino board by clicking on the **Upload** button.

9. Once the code is uploaded successfully, open the serial monitor to view the system output.

## Usage

1. Press key 'A' to make the robot walk forward.

2. Press key 'B' to make the robot walk backward.

3. Press key 'C' to make the robot stop.

4. Press '*' to make the robot turn left.

5. Press '#' to make the robot turn right.

## Customization

You can customize the access control logic and actions according to your requirements. In the `Quiz1.ino` file, you will find comments and instructions to guide you through the customization process.



## Contributing

Contributions to this project are welcome. If you find any issues or have suggestions for improvements, please open an issue on the GitHub repository.

## License

This project is licensed under the [MIT License](LICENSE).
