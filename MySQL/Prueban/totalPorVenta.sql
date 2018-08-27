select no_venta, 
sum(venta.subtotal) as total_precio,
sum(venta.cantidad) as total_productos
from(
select no_venta, nombre, ean, precio, cantidad, precio*cantidad as subtotal from ticket_venta
	natural join producto_ticket_venta
    natural join producto
    ) as venta
    group by no_venta;
    