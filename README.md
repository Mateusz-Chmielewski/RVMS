![RVMS](./docs/images/RVMS.png)
# Introduction
**Room Ventilation Monitoring System** is a network of self-made sensor-signal devices deployed in the [school](https://zsel.edu.pl/index.php). The system is designed to inform school staff of the necessity of ventilating a room, as well as collect data for research on the impact of air quality on work and learning efficiency. The project took part in the Explory 2022 science festival in Olsztyn.

# Sensor

## Used Components
- Microcontroller ESP 8266 
- Photoelectric sensor MH-Z19
- External power supply 12V 1.5A
- Step-down inverter MP1454EN
- Led diods WS2812B

# Application
## Backend
Spring Boot application resposible for collecting data from sensors, processing and storaging in database. Apps can communicate with it using REST API interface.
![Diagram](./docs/diagram.drawio)

## Web Application
React application that allows user viewing of collected data. The data is presented in the form of clear graphs. After logging in as an administrator, the user can manage sensors.
### Results Preview
![Results Preview](./docs/images/results_preview.png)
### Admin Panel


## Used Technologies
- Java 17
- Maven
- Spring Boot
- My SQL database
- React

# Installation