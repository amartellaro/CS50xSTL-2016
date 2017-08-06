<table class="table table-striped">

    <thead>
        <tr>
            <th>Symbol</th>
            <th>Name</th>
            <th>Shares</th>
            <th>Price</th>
            <th>TOTAL</th>
        </tr>
    </thead>

    <tbody>

    
    <?php 
    foreach ($positions as $position):  
    
    $total = ($position["price"] * $position["shares"]);
    $cash = CS50::query("SELECT cash FROM users WHERE id = '$_SESSION[id]'");
    $cash = array_pop($cash);
    $cash = (float)$cash["cash"];
    ?>

    <tr>
        <td align="left"><?= $position["symbol"] ?></td>
        <td align="left"><?= $position["name"] ?></td>
        <td align="left"><?= $position["shares"] ?></td>
        <td align="left">$<?= number_format("$position[price]", 2); ?></td>
        <td align="left">$<?= number_format("$total", 2); ?></td>
    </tr>

<?php endforeach ?>
    
    <tr>
        <td align="left" colspan="4">CASH</td>
        <td align="left">$<?= number_format($cash, 2); ?></td>
    </tr>

    </tbody>

</table>

<center>
<form action="/add_funds.php">
    <input type="submit" value="Add Funds">
</form>
</center>