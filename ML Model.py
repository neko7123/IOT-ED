
# Import necessary libraries
import numpy as np
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import accuracy_score
from sklearn.externals import joblib  # For saving the trained model

# Generate synthetic data for demonstration purposes
np.random.seed(42)
num_samples = 1000
x = np.random.rand(num_samples)  # Replace with actual x-axis data
y = np.random.rand(num_samples)  # Replace with actual y-axis data
z = np.random.rand(num_samples)  # Replace with actual z-axis data

# Create labels (0: not earthquake, 1: earthquake)
labels = np.random.randint(2, size=num_samples)  # Replace with actual labels

# Split the data into training and testing sets
x_train, x_test, y_train, y_test, z_train, z_test, labels_train, labels_test = train_test_split(
    x, y, z, labels, test_size=0.2, random_state=42)

# Standardize the data
scaler = StandardScaler()
x_train_scaled = scaler.fit_transform(np.column_stack((x_train, y_train, z_train)))
x_test_scaled = scaler.transform(np.column_stack((x_test, y_test, z_test)))

# Train a Random Forest Classifier
clf = RandomForestClassifier(random_state=42)
clf.fit(x_train_scaled, labels_train)

# Make predictions on the test set
predictions = clf.predict(x_test_scaled)

# Evaluate the model
accuracy = accuracy_score(labels_test, predictions)
print(f"Accuracy: {accuracy * 100:.2f}%")

# Save the trained model
joblib.dump(clf, "earthquake_model.joblib")

# Example usage for new data
new_data = np.array([[0.1, 0.2, 0.3]])  # Replace with actual displacement values
new_data_scaled = scaler.transform(new_data)
prediction = clf.predict(new_data_scaled)

if prediction[0] == 1:
    print("Warning: Earthquake detected!")
else:
    print("No earthquake detected.")