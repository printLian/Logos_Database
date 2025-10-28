<?php
// Check if the form was submitted
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Database credentials
    $servername = "localhost";
    $username = "root";
    $password = "";
    $dbname = "user_registration_db";

    // Create connection
    $conn = new mysqli($servername, $username, $password, $dbname);

    // Check connection
    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }

    // Sanitize and validate input
    $name = $conn->real_escape_string($_POST['name']);
    $password = $conn->real_escape_string($_POST['password']);
    $city_address = $conn->real_escape_string($_POST['city_address']);
    $contact_number = $conn->real_escape_string($_POST['contact_number']);

    // Hash the password for security
    $hashed_password = password_hash($password, PASSWORD_DEFAULT);

    // SQL query to insert data into the 'users' table
    $sql = "INSERT INTO users (name, password, city_address, contact_number) VALUES (?, ?, ?, ?)";
    
    // Prepare the statement to prevent SQL injection
    $stmt = $conn->prepare($sql);
    $stmt->bind_param("ssss", $name, $hashed_password, $city_address, $contact_number);
    
    // Execute the statement
    if ($stmt->execute()) {
        $message = "Registration successful!";
    } else {
        $message = "Error: " . $stmt->error;
    }

    $stmt->close();
    $conn->close();
}
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>User Registration</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>

    <div class="container">
        <h1>User Registration</h1>

        <?php if (isset($message)): ?>
            <p class="message"><?= $message ?></p>
        <?php endif; ?>

        <form action="register.php" method="post">
            <div class="form-group">
                <label for="name">Name:</label>
                <input type="text" id="name" name="name" required>
            </div>
            <div class="form-group">
                <label for="password">Password:</label>
                <input type="password" id="password" name="password" required>
            </div>
            <div class="form-group">
                <label for="city_address">City Address:</label>
                <input type="text" id="city_address" name="city_address" required>
            </div>
            <div class="form-group">
                <label for="contact_number">Contact Number:</label>
                <input type="text" id="contact_number" name="contact_number" required>
            </div>
            <button type="submit">Register</button>
        </form>

        <p class="view-link"><a href="display_users.php">View Registered Users</a></p>
    </div>

</body>
</html>
