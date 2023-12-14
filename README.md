# IOT Based Earthquake Prediction System

1)Overview

This repository contains the source code and documentation for an Earthquake Prediction System. The system utilizes machine learning to analyze vibrations measured by an Arduino sensor. The trained model predicts whether the detected vibrations are indicative of an earthquake or not. The predictions are then sent to a dedicated app for real-time monitoring and warnings.
![Screenshot 2023-12-14 181849](https://github.com/neko7123/IOT-ED/assets/114769390/75fb25d5-fca5-48f5-8c72-b168218ec47f)

## Components

a)Arduino Sensor Code:
Arduino code to read vibrations from sensors connected to the x, y, and z axes.
Establishes server connectivity to send data to the machine learning model.

b)Machine Learning Model:
Python code for training a Random Forest Classifier on displacement values.
Utilizes the scikit-learn library for data preprocessing, model training, and evaluation.
Saves the trained model for real-time predictions.
Server Connectivity:

c)Manages communication between the Arduino sensor and the machine learning model.
Handles data transmission and reception to enable real-time predictions.

d)Dedicated App:
Android application for receiving and displaying earthquake predictions.
Receives warnings from the server based on the machine learning model's predictions.
Provides user-friendly interface for monitoring seismic activity.
Usage

## Setup

a)Connect the sensors to the Arduino board following the provided schematic.
Upload the Arduino sensor code to read and send vibration data.
Machine Learning Model:

b)Train the model using your dataset (or use the provided example with synthetic data).
Save the trained model using joblib for real-time predictions.
Server Setup:

c)Configure the server to establish a connection with the Arduino.
Implement the necessary communication protocols for data transmission.

## APP

Install the app on your mobile device.
Connect the app to the server to receive real-time earthquake predictions.

![6](https://github.com/neko7123/IOT-ED/assets/114769390/331d3299-6d36-4065-8c83-9e13b994b497)
![5](https://github.com/neko7123/IOT-ED/assets/114769390/43f5c585-4aff-4bb5-a636-de2b88fb7e53)
![4](https://github.com/neko7123/IOT-ED/assets/114769390/9d28650a-f134-4c54-bc88-f42224058400)
![3](https://github.com/neko7123/IOT-ED/assets/114769390/f720d084-c2a8-4335-966b-148165b34a13)
![2](https://github.com/neko7123/IOT-ED/assets/114769390/8f8d50c8-e741-4e18-99d8-cf783d503cfa)
![1](https://github.com/neko7123/IOT-ED/assets/114769390/9184b850-6b9f-43cc-b9b9-528ff8804297)


## Dependencies

Arduino IDE, Python 3.x, scikit-learn, joblib, matplotlib, pandas, numpy
