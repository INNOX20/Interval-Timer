### Millis() based Timer Library
This library provides a simplified and easy-to-use implementation of timers based on the `millis()` function in electronic projects. The `millis()` function provides the elapsed time in milliseconds since the start of the program, and this library takes advantage of that functionality to create precise and flexible timers.

The library includes an `IntervalTimer` class that allows you to set time intervals and execute callbacks when each interval is reached. In addition, auxiliary functions are provided to set the timers, reset them, and control their interval.

Using this library, developers can easily create applications that require precise timing, such as triggering periodic events, blinking LEDs, controlling actuators, and much more.

####Example code in arduino

	// Pin assignments for LEDs
	const int LED_PIN_0 = 13;  // Pin for the first LED
	const int LED_PIN_1 = 12;  // Pin for the second LED
	const int LED_PIN_2 = 11;  // Pin for the third LED
	const int LED_PIN_3 = 10;  // Pin for the fourth LED

	// Interval timers with their respective callback functions
	IntervalTimer timer0(200, toggleLED0);                // Timer for the first LED with a 200ms interval
	IntervalTimer timer1(seconds(1), toggleLED1);        // Timer for the second LED with a 1s interval
	IntervalTimer timer2(minutes(2), toggleLED2);        // Timer for the third LED with a 2-minute interval
	IntervalTimer timer3(hours(1), toggleLED3);          // Timer for the fourth LED with a 1-hour interval

	void setup() {
	  // Configure pin modes for LED control
	  pinMode(LED_PIN_0, OUTPUT);
	  pinMode(LED_PIN_1, OUTPUT);
	  pinMode(LED_PIN_2, OUTPUT);
	  pinMode(LED_PIN_3, OUTPUT);
	}

	void loop() {
	  // Update the timers
	  timer0.update();
	  timer1.update();
	  timer2.update();
	  timer3.update();
	}

	void toggleLED(int pin) {
	  // Toggle the state of the specified LED pin
	  digitalWrite(pin, !digitalRead(pin));
	}

	void toggleLED0() {
	  // Callback function for the first LED timer
	  toggleLED(LED_PIN_0);
	}

	void toggleLED1() {
	  // Callback function for the second LED timer
	  toggleLED(LED_PIN_1);
	}

	void toggleLED2() {
	  // Callback function for the third LED timer
	  toggleLED(LED_PIN_2);
	}

	void toggleLED3() {
	  // Callback function for the fourth LED timer
	  toggleLED(LED_PIN_3);
	}

###IntervalTimer Class Functionality

Managing Timers and Callbacks

Description: This section describes the functions and behavior of the `IntervalTimer` class, which provides convenient functionality for managing timers and executing callbacks at specific intervals. The class includes the `update()`, `setInterval()`, and `reset()` methods, along with private variables for interval management. These features enable precise control over time-based operations and facilitate the execution of repetitive tasks in embedded systems and other applications.

### IntervalTimer Class Functionality

Description: This section describes the functions and behavior of the `IntervalTimer` class, which provides convenient functionality for managing timers and executing callbacks at specific intervals. The class includes the following methods and parameters:

Method: `update()`
   - Parameters: None
   - Description: Checks if enough time has elapsed since the last callback execution. If the elapsed time is greater than or equal to the next trigger time, the callback function is invoked.

Method: `setInterval(unsigned long interval)`
   - Parameters:
     - `interval`: The new interval in milliseconds.
   - Description: Allows changing the timer's interval by updating the value of `_interval`.

Method: `reset()`
   - Parameters: None
   - Description: Resets the timer by setting the next trigger time to the current time plus the timer's interval.

These features enable precise control over time-based operations and facilitate the execution of repetitive tasks in embedded systems and other applications.
