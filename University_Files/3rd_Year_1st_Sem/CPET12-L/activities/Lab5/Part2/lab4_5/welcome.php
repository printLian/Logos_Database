<?php
// Start the session
session_start();

// Check if the user is logged in. If not, redirect to the	 login page.
if (!isset($_SESSION['loggedin']) || $_SESSION['loggedin'] !== true) {
    header("Location: index.html");
    exit();
}
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Welcome</title>
</head>
<body>
    <h2>Welcome, <?php echo htmlspecialchars($_SESSION['username']); ?>!</h2>
    <p>You have successfully logged in.</p>
    <a href="logout.php">Logout</a>
</body>
</html>
