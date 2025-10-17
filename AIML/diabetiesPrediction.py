# -----------------------------------------------------------
# Title: Prediction of Diabetes using Decision Tree Classifier
# -----------------------------------------------------------

# Step 1: Import Libraries
import pandas as pd
from sklearn.tree import DecisionTreeClassifier, export_graphviz
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score, confusion_matrix, classification_report
from sklearn import tree
import graphviz

# Step 2: Load Dataset
data = pd.read_csv("diabetes.csv", encoding='utf8')
print("First 5 rows of dataset:\n", data.head())

# Step 3: Select Features and Target
feature_cols = ['Pregnancies', 'Insulin', 'BMI', 'Age', 'Glucose', 'BloodPressure', 'DiabetesPedigreeFunction']
X = data[feature_cols]
y = data['Outcome']

# Step 4: Split Data
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
print("\nTraining and testing data split completed.")

# Step 5: Train Decision Tree Model
model = DecisionTreeClassifier(criterion='entropy', random_state=42)
model.fit(X_train, y_train)
print("\nModel training completed using Decision Tree Classifier (criterion='entropy').")

# Step 6: Make Predictions
y_pred = model.predict(X_test)

# Step 7: Evaluate Model
print("\nConfusion Matrix:\n", confusion_matrix(y_test, y_pred))
print("\nClassification Report:\n", classification_report(y_test, y_pred))
print("\nAccuracy of the model:", round(accuracy_score(y_test, y_pred) * 100, 2), "%")

# Step 8: Predict for New Input
# Example input format: [Pregnancies, Insulin, BMI, Age, Glucose, BloodPressure, DiabetesPedigreeFunction]
new_data = [[2, 130, 30.5, 45, 150, 70, 0.5]]
print("\nFeature columns:", feature_cols)
print("\nNew data to predict:", new_data)
new_data_df = pd.DataFrame(new_data, columns=feature_cols)
prediction = model.predict(new_data_df)
result = "Diabetic" if prediction[0] == 1 else "Non-Diabetic"
print("\nPrediction for new input:", result)
