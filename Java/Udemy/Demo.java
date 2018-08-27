

import java.util.ArrayList;

public class Demo {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Player tim = new Player("Tom Smith", 7);
//		System.out.println(tim.getHandleName());
//		System.out.println(tim.getWeapon().getName());

		Weapon myAxe = new Weapon("GoldShine Aze", 15, 50);
		tim.setWeapon(myAxe);
//		System.out.println(tim.getWeapon().getName());
		InventoryItem redPotion = new InventoryItem(ItemType.POTION, "Red Potion");
		tim.addInventoryItem(redPotion);
		tim.addInventoryItem(new InventoryItem(ItemType.ARMOR, "+3 Chest Armor"));
		tim.addInventoryItem(new InventoryItem(ItemType.RING, "Ring of Protection +2"));
		tim.addInventoryItem(new InventoryItem(ItemType.POTION, "Invisibility Potion"));

		InventoryItem bluePotion = new InventoryItem(ItemType.POTION, "Blue Potion");

		boolean wasDeleted = tim.dropInventoryItem(redPotion);
		System.out.println(wasDeleted);

		ArrayList<InventoryItem> allItems = tim.getInventoryitems();
		for (InventoryItem item : allItems) {
			System.out.println(item.getName());
		}

	}

}
