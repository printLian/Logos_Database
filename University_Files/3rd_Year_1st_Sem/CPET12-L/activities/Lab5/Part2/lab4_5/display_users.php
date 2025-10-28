<?php
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

// SQL query to fetch all users
$sql = "SELECT id, name, city_address, contact_number FROM users";
$result = $conn->query($sql);

?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Registered Users</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>

    <div class="container">
        <h1>Registered Users</h1>

        <?php
        if ($result->num_rows > 0) {
            echo "<table>";
            echo "<thead><tr><th>ID</th><th>Name</th><th>City Address</th><th>Contact Number</th></tr></thead>";
            echo "<tbody>";

            while($row = $result->fetch_assoc()) {
                echo "<tr>";
                echo "<td>" . $row["id"] . "</td>";
                echo "<td>" . $row["name"] . "</td>";
                echo "<td>" . $row["city_address"] . "</td>";
                echo "<td>" . $row["contact_number"] . "</td>";
                echo "</tr>";
            }

            echo "</tbody>";
            echo "</table>";
        } else {
            echo "<p>No users registered yet.</p>";
        }

        $conn->close();
        ?>
    </div>

</body>
</html>
