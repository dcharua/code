select sum(venta.subtotal) as total_precio,
sum(venta.cantidad) as total_productos
from(
select nombre, ean, precio, cantidad, precio*cantidad as subtotal from ticket_venta
	natural join producto_ticket_venta
    natural join producto
    where no_venta = 4
    ) as venta
    