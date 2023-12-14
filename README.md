# IOT Based Earthquake Prediction System

1)Overview

This repository contains the source code and documentation for an Earthquake Prediction System. The system utilizes machine learning to analyze vibrations measured by an Arduino sensor. The trained model predicts whether the detected vibrations are indicative of an earthquake or not. The predictions are then sent to a dedicated app for real-time monitoring and warnings.

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

## Dependencies

Arduino IDE, Python 3.x, scikit-learn, joblib, matplotlib, pandas, numpy
