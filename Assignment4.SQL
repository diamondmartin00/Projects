CREATE TABLE dem_customer (
customerID INT PRIMARY KEY,
customerLastName VARCHAR2(25) NOT NULL,
customerFirstName VARCHAR2(20), 
customerCity VARCHAR2(25),
customerState VARCHAR2(2),
customerZIP VARCHAR2(10),
customerEmail VARCHAR2(25) NOT NULL,
customerPhoneNum VARCHAR2(25) ) ;
INSERT INTO dem_customer (
customerID,customerLastName,customerFirstName,
customerCity,customerState,customerZIP,customerEmail,
customerPhoneNum) VALUES (1,'Alexander','Michael','Highland Heights','KY','41076','alexander@yahoo.com',NULL) ;
INSERT INTO dem_customer (
customerID,customerLastName,customerFirstName,
customerCity,customerState,customerZIP,customerEmail,
customerPhoneNum) VALUES (2,'Clark','Franklin','Amelia','OH','45102','clifton@gmail.com', '513-293-4435') ;
INSERT INTO dem_customer (
customerID,customerLastName,customerFirstName,
customerCity,customerState,customerZIP,customerEmail,
customerPhoneNum) VALUES (3,'Philps','Trevor','Newtown','OH','45244','tphilips@hotmail.com', NULL) ;
INSERT INTO dem_customer (
customerID,customerLastName,customerFirstName,
customerCity,customerState,customerZIP,customerEmail,
customerPhoneNum) VALUES (4,'Butler','Ashley','Erlanger','KY','41017','abutler@gmail.com', '859-563-8090') ;
INSERT INTO dem_customer (
customerID,customerLastName,customerFirstName,
customerCity,customerState,customerZIP,customerEmail,
customerPhoneNum) VALUES (5,'Landon','Frank','Reading','OH','45215','flandon@yahoo.com',NULL) ;
INSERT INTO dem_customer (
customerID,customerLastName,customerFirstName,
customerCity,customerState,customerZIP,customerEmail,
customerPhoneNum) VALUES (6,'Herbert','Floyd','Cincinnati','OH','45211','fherbert@gmail.com',NULL) ;
INSERT INTO dem_customer (
customerID,customerLastName,customerFirstName,
customerCity,customerState,customerZIP,customerEmail,
customerPhoneNum) VALUES (7,'McGee','Martin','Cincinnati','OH','45238','mmcgee@gmail.com', NULL) ;
COMMIT WORK;

CREATE TABLE dem_supplier (
supplierID INT PRIMARY KEY,
supplierName VARCHAR2(25) NOT NULL,
supplierCity VARCHAR2(20),
supplierState VARCHAR2(2),
supplierContactName VARCHAR2(25),
supplierContactTitle VARCHAR2(30),
supplierContactEmail VARCHAR2(30)
) ;
INSERT INTO dem_supplier (
supplierID,supplierName,supplierCity,supplierState,supplierContactName, supplierContactTitle,supplierContactEmail) VALUES (1,'Reaper','Denton','TX','John Franklin','Product Marketing Manager','jfranklin@reaper.com') ;
INSERT INTO dem_supplier (
supplierID,supplierName,supplierCity,supplierState,supplierContactName,supplierContactTitle,supplierContactEmail) VALUES (2,'Ironwind Metals','Cincinnati','OH','Tim McDonald','Sales Manager','tim.mcdonald@ironwind.com') ;
INSERT INTO dem_supplier (
supplierID,supplierName,supplierCity,supplierState,supplierContactName,supplierContactTitle,supplierContactEmail) VALUES (3,'Wizards of the Coast','Seattle','WA','Brad Edelman','Senior Sales Associate','Senior Sales Associate') ;
INSERT INTO dem_supplier (
supplierID,supplierName,supplierCity,supplierState,supplierContactName,supplierContactTitle,supplierContactEmail) VALUES (15,'Mega Miniatures','Augusta','MI','President','President','jlauck@yahoo.com') ;
COMMIT WORK;
CREATE TABLE dem_order (
orderID INT PRIMARY KEY,
customerID INT NOT NULL REFERENCES dem_customer(customerID),
orderDate DATE NOT NULL,
orderStatus VARCHAR2(2) NOT NULL,
orderShippedDate DATE ) ;
INSERT INTO dem_order (
orderID,customerID,orderDate,orderStatus,orderShippedDate) VALUES (1,1,TO_DATE('2018-03-01','yyyy-mm-dd'),'SP',TO_DATE('2018-03-04','yyyy-mm-dd') );
INSERT INTO dem_order (
orderID,customerID,orderDate,orderStatus,orderShippedDate) VALUES (2,2,TO_DATE('2018-03-02','yyyy-mm-dd'),'SP',TO_DATE('2018-03-04','yyyy-mm-dd') );
INSERT INTO dem_order (
orderID,customerID,orderDate,orderStatus,orderShippedDate) VALUES (3,3,TO_DATE('2018-03-03','yyyy-mm-dd'),'SP',TO_DATE('2018-03-05','yyyy-mm-dd') );
INSERT INTO dem_order (
orderID,customerID,orderDate,orderStatus,orderShippedDate) VALUES (4,4,TO_DATE('2018-03-03','yyyy-mm-dd'),'SP',TO_DATE('2018-03-05','yyyy-mm-dd') );
INSERT INTO dem_order (
orderID,customerID,orderDate,orderStatus,orderShippedDate) VALUES (5,5,TO_DATE('2018-03-05','yyyy-mm-dd'),'SP',TO_DATE('2018-03-07','yyyy-mm-dd') );
INSERT INTO dem_order (
orderID,customerID,orderDate,orderStatus,orderShippedDate) VALUES (6,6,TO_DATE('2018-03-05','yyyy-mm-dd'),'SP',TO_DATE('2018-03-08','yyyy-mm-dd') );
INSERT INTO dem_order (
orderID,customerID,orderDate,orderStatus,orderShippedDate) VALUES (7,7,TO_DATE('2018-03-08','yyyy-mm-dd'),'SP',TO_DATE('2018-03-10','yyyy-mm-dd') );
INSERT INTO dem_order (
orderID,customerID,orderDate,orderStatus,orderShippedDate) VALUES (16,2,TO_DATE('2018-03-15','yyyy-mm-dd'),'SP',TO_DATE('2018-03-17','yyyy-mm-dd') );
INSERT INTO dem_order (
orderID,customerID,orderDate,orderStatus,orderShippedDate)
VALUES (17,4,TO_DATE('2018-03-16','yyyy-mm-dd'),'SP',TO_DATE('2018-03-19','yyyy-mm-dd'));
INSERT INTO dem_order (
orderID,customerID,orderDate,orderStatus,orderShippedDate)
VALUES (20,7,TO_DATE('2018-03-18','yyyy-mm-dd'),'SP',TO_DATE('2018-03-20','yyyy-mm-dd'));
INSERT INTO dem_order (
orderID,customerID,orderDate,orderStatus,orderShippedDate)
VALUES (23,5,TO_DATE('2018-03-20','yyyy-mm-dd'),'SP',TO_DATE('2018-03-22','yyyy-mm-dd'));
COMMIT WORK;
        
CREATE TABLE dem_product (
productCode VARCHAR2(15) PRIMARY KEY,
supplierID INT NOT NULL REFERENCES dem_supplier(supplierID),
productName VARCHAR2(30) NOT NULL,
productSuggestedPrice NUMBER(5,2),
productUnitsInStock NUMBER(3),
productUnitsOnOrder NUMBER(3),
productDiscontinued VARCHAR2(1) ) ;
INSERT INTO dem_product (
productCode,supplierID,productName,productSuggestedPrice,productunitsInStock,productunitsOnOrder,productDiscontinued) VALUES ('IM511',2,'Cloaked Assassin',4.95,4,1,'N') ;
INSERT INTO dem_product (
productCode,supplierID,productName,productSuggestedPrice,productunitsInStock,productunitsOnOrder,productDiscontinued) VALUES ('IM514',2,'Hooded Female Thief',4.25,3,0,'N') ;
INSERT INTO dem_product (
productCode,supplierID,productName,productSuggestedPrice,productunitsInStock,productunitsOnOrder,productDiscontinued) VALUES ('IM517',2,'Cleric with Staff',4.95,5,2,'N') ;
INSERT INTO dem_product (
productCode,supplierID,productName,productSuggestedPrice,productunitsInStock,productunitsOnOrder,productDiscontinued) VALUES ('IM519',2,'Berserker',3.71,2,1,'N') ;
INSERT INTO dem_product(
productCode,supplierID,productName,productSuggestedPrice,productunitsInStock,productunitsOnOrder,productDiscontinued) VALUES ('IM527',2,'Grand Mystic',4.95,3,0,'N') ;
INSERT INTO dem_product(
productCode,supplierID,productName,productSuggestedPrice,productunitsInStock,productunitsOnOrder,productDiscontinued) VALUES ('IM537',2,'Hydra',29.95,3,0,'Y') ;
INSERT INTO dem_product (
productCode,supplierID,productName,productSuggestedPrice,productunitsInStock,productunitsOnOrder,productDiscontinued) VALUES ('IM539',2,'Umber Hulk',11.59,4,1,'N') ;
INSERT INTO dem_product (productCode,supplierID,productName,productSuggestedPrice,productunitsInStock,productunitsOnOrder,productDiscontinued) VALUES ('IM540',2,'Wraith',5.25,6,2,'N') ;
INSERT INTO dem_product (productCode,supplierID,productName,productSuggestedPrice,productunitsInStock,productunitsOnOrder,productDiscontinued) VALUES ('IM556',2,'Heroic Paladin',5.99,7,3,'N') ;
INSERT INTO dem_product (productCode,supplierID,productName,productSuggestedPrice,productunitsInStock,productunitsOnOrder,productDiscontinued) VALUES ('IM657',2,'Two-Headed Troll',12.99,2,0,'Y') ;
INSERT INTO dem_product (productCode,supplierID,productName,productSuggestedPrice,productunitsInStock,productunitsOnOrder,productDiscontinued) VALUES ('R03495',1,'Werewolf',9.99,3,0,'Y') ;
INSERT INTO dem_product (productCode,supplierID,productName,productSuggestedPrice,productunitsInStock,productunitsOnOrder,productDiscontinued) VALUES ('R03515',1,'Dervish Warrior',4.99,4,2,'N') ;
INSERT INTO dem_product (productCode,supplierID,productName,productSuggestedPrice,productunitsInStock,productunitsOnOrder,productDiscontinued) VALUES ('R03527',1,'Scourge Devil',11.99,1,2,'N') ;
INSERT INTO dem_product (productCode,supplierID,productName,productSuggestedPrice,productunitsInStock,productunitsOnOrder,productDiscontinued) VALUES ('R03581',1,'Human Ranger',7.49,9,2,'N') ;
INSERT INTO dem_product (productCode,supplierID,productName,productSuggestedPrice,productunitsInStock,productunitsOnOrder,productDiscontinued) VALUES ('R03669',1,'Dark Elf',7.99,8,0,'N') ;
COMMIT WORK;

CREATE TABLE dem_orderLine (
orderLineID INT PRIMARY KEY,
orderID INT NOT NULL REFERENCES dem_order(orderID),
productCode VARCHAR2(15) NOT NULL REFERENCES dem_product(productCode),
orderLineQuantity NUMBER(3) NOT NULL,
orderLineUnitPrice NUMBER(5,2) NOT NULL) ;
INSERT INTO dem_orderLine (
orderLineID,orderID,productCode,orderLineQuantity,orderLineUnitPrice ) VALUES (1,1,'IM511',1,5.49);
INSERT INTO dem_orderLine (
orderLineID,orderID,productCode,orderLineQuantity,orderLineUnitPrice ) VALUES (2,1,'R03495',1,10.99);
INSERT INTO dem_orderLine (
orderLineID,orderID,productCode,orderLineQuantity,orderLineUnitPrice ) VALUES (3,2,'IM514',1,4.99);
INSERT INTO dem_orderLine (
orderLineID,orderID,productCode,orderLineQuantity,orderLineUnitPrice ) VALUES (4,3,'IM517',1,4.99);
INSERT INTO dem_orderLine (
orderLineID,orderID,productCode,orderLineQuantity,orderLineUnitPrice ) VALUES (5,4,'R03515',1,5.99);
INSERT INTO dem_orderLine (
orderLineID,orderID,productCode,orderLineQuantity,orderLineUnitPrice ) VALUES (6,5,'R03669',1,8.99);
INSERT INTO dem_orderLine (
orderLineID,orderID,productCode,orderLineQuantity,orderLineUnitPrice ) VALUES (7,6,'IM657',1,12.99);
INSERT INTO dem_orderLine (
orderLineID,orderID,productCode,orderLineQuantity,orderLineUnitPrice ) VALUES (9,7,'R03527',1,11.99);
INSERT INTO dem_orderLine (
orderLineID,orderID,productCode,orderLineQuantity,orderLineUnitPrice ) VALUES (8,7,'R03581',2,7.49);
INSERT INTO dem_orderLine (
orderLineID,orderID,productCode,orderLineQuantity,orderLineUnitPrice ) VALUES (19,16,'IM527',1,4.95);
INSERT INTO dem_orderLine (
orderLineID,orderID,productCode,orderLineQuantity,orderLineUnitPrice ) VALUES (18,16,'IM537',1,34.95);
INSERT INTO dem_orderLine (
orderLineID,orderID,productCode,orderLineQuantity,orderLineUnitPrice ) VALUES (20,16,'IM540',1,5.99);
INSERT INTO dem_orderLine (
orderLineID,orderID,productCode,orderLineQuantity,orderLineUnitPrice ) VALUES (21,17,'IM556',1,6.99);
INSERT INTO dem_orderLine (
orderLineID,orderID,productCode,orderLineQuantity,orderLineUnitPrice ) VALUES (27,20,'IM519',1,4.19);
INSERT INTO dem_orderLine (
orderLineID,orderID,productCode,orderLineQuantity,orderLineUnitPrice ) VALUES (31,23,'IM539',1,12.49);
COMMIT WORK;