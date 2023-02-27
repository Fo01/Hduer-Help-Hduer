# Trigger example

DELIMITER //

# delete order_items before order to avoid referential integrity error
CREATE TRIGGER Delete_Order_Items 
BEFORE DELETE ON Orders FOR EACH ROW
BEGIN
  DELETE FROM Order_Items WHERE OLD.OrderID = OrderID;
END 
//

DELIMITER ;



