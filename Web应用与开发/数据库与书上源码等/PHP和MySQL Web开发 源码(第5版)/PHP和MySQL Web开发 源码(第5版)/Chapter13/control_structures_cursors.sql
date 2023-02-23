# Procedure to find the orderid with the largest amount
# could be done with max, but just to illustrate stored procedure principles

DELIMITER //

CREATE PROCEDURE Largest_Order (OUT Largest_ID INT)
BEGIN
  DECLARE This_ID INT;
  DECLARE This_Amount FLOAT;
  DECLARE L_Amount FLOAT DEFAULT 0.0;
  DECLARE L_ID INT;

  DECLARE Done INT DEFAULT 0;
  DECLARE C1 CURSOR FOR SELECT OrderID, Amount FROM Orders;
  DECLARE CONTINUE HANDLER FOR SQLSTATE '02000' SET Done = 1;

  OPEN C1;
  REPEAT
    FETCH C1 INTO This_ID, This_Amount;
    IF NOT Done THEN
      IF This_Amount > L_Amount THEN
        SET L_Amount=This_Amount;
        SET L_ID=This_ID;
      END IF;
    END IF;
   UNTIL Done END REPEAT;
  CLOSE C1;

 
  SET LARGEST_ID=L_ID;

END
//

DELIMITER ;
