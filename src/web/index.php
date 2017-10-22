  <html>
  <head>
    <script type="text/javascript" src="https://www.gstatic.com/charts/loader.js"></script>
  </head>
  <body>
    <?php
        $mysqli = new mysqli("localhost", "root", "", "db-arduino-sensors");
        if ($mysqli->connect_errno) {
            echo "Echec lors de la connexion à MySQL : (" . $mysqli->connect_errno . ") " . $mysqli->connect_error;
        }
        $res = $mysqli->query("SELECT * FROM temperature");
    ?>
    <div id="curve_chart" style="width: 1500px; height: 800px"></div>

    <script type="text/javascript">
      google.charts.load('current', {'packages':['corechart']});
      google.charts.setOnLoadCallback(drawChart);

      function drawChart() {
        var data = google.visualization.arrayToDataTable([
          ['Time', 'Temperature'],
          <?php
            for($row_no = 0; $row_no <= $res->num_rows - 1; $row_no++){
                $res->data_seek($row_no);
                $row = $res->fetch_assoc();
                echo "['" . $row["created_at"] . "', " . $row["temperature"] . "]," ;
             } ?>
          //['2007',  28.5]
        ]);

        var options = {
          title: 'Temperature in my house',
          curveType: 'function',
          legend: { position: 'bottom' }
        };

        var chart = new google.visualization.LineChart(document.getElementById('curve_chart'));

        chart.draw(data, options);
      }
    </script>
  </body>
</html>