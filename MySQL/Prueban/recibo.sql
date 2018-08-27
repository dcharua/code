select * from ticket_venta
	inner join empleado on (no_empleado = id_empleado)
    where no_venta = 4;
    
select nombre, ean, precio, cantidad, precio*cantidad as subtotal from ticket_venta
	natural join producto_ticket_venta
    natural join producto
    where no_venta = 4;