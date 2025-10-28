<?php
// Database connection details
$servername = "localhost";
$username = "root"; // Default XAMPP username
$password = ""; // Default XAMPP password
$dbname = "user_registration_db";

// Create database connection 
$conn = new mysqli($servername, $username, $password, $dbname);

// Check connection

// Check if form data has been submitted
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Get username and password from the form
    $input_username = $_POST['username'];
    $input_password = $_POST['password'];

    // Prepare and execute the SQL query to find the user
    // Use prepared statements to prevent SQL injection
    $stmt = $conn->prepare("SELECT password FROM users WHERE name = ?");
    $stmt->bind_param("s", $input_username);
    $stmt->execute();
    $stmt->bind_result($db_password);
    $stmt->fetch();
    $stmt->close();

    // Check if a user with the given username was found
    if ($db_password && password_verify($input_password, $db_password)) {
        // Start a session and store user data
        session_start();
        $_SESSION['loggedin'] = true;
        $_SESSION['username'] = $input_username;

        // Redirect to the welcome page
        header("Location: welcome.php");
        exit();
    } else {
        // Login failed, display an error message
        echo "Invalid username or password.";
    }
}

$conn->close();
?>