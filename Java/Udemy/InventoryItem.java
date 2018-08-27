

enum ItemType { POTION, RING, ARMOR }

public class InventoryItem {

	private ItemType type;
	private String name;

	public InventoryItem(ItemType type, String name) {
		super();
		this.type = type;
		this.name = name;
	}

	public ItemType getType() {
		return type;
	}

	public void setType(ItemType type) {
		this.type = type;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}
}
