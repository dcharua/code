import java.io.*;
import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;
import java.util.SortedSet;
import java.util.TreeSet;

/**
 * Implementation of Map with out source file
 * for over sized values
 *
 * @param <K>
 * @param <V>
 */
public class FileMap<K,V> implements Map<K,V>, Serializable{

	private HashMap<K,Location> map;
	private RandomAccessFile raf;


	public FileMap(String filename)
	{
		map= new HashMap<K,Location>();
		try {
			raf=new RandomAccessFile(filename, "rw");
		}
		catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}

	public FileMap()
	{
		map= new HashMap<K,Location>();
		try{
		raf=new RandomAccessFile(File.createTempFile("FileMapTemp", "bin"), "rw");
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}

	/**
	 * saves Location in file of each value in map
	 *
	 */
	protected class Location{
		private long loc;
		private long size;

		protected Location(long l, long m)
		{
			this.size=m;
			loc=l;
		}

		/**
		 *
		 * @return long
		 */
		protected long getLocation()
		{
			return loc;
		}

		/**
		 *
		 * @return long
		 */
		protected long getBuffSize()
		{
			return size;
		}
	}

/**
 * puts Object in FileMap
 *
 * @return V
 * @param K key, V value
 */
	public V put(K key, V value){
		try {
			byte[] buff = this.serialize(value, key);
			long index= raf.getFilePointer();
			raf.write(buff);
			if(map.containsKey(key))
			{
				long all_prev= map.get(key).getBuffSize();
				map.put(key, new Location(index, (raf.getFilePointer()-index)+all_prev));
			}
			else
				map.put(key, new Location(index, raf.getFilePointer()-index));
			return value;
		} catch (IOException e) {
			e.printStackTrace();
			return null;
		}
	}

/**
 *
 *
 * @param val
 * @return
 */
	private byte[] serialize(V val, K key)
	{
		FileOutputStream fos;
		try {
		ByteArrayOutputStream bos = new ByteArrayOutputStream();
		ObjectOutput out = new ObjectOutputStream(bos);
        out.writeObject(val);
		String file = key+".ser";
			 fos = new FileOutputStream(file);
				 ObjectOutputStream oos = new ObjectOutputStream(fos);
				 oos.writeObject(val);
			byte[] rawData = bos.toByteArray();
			oos.close();
			return rawData;
		} catch (IOException e) {
			e.printStackTrace();
			return null;
		}
	}

	@SuppressWarnings("unchecked")
/**
 *
 * @param rawData
 * @return V
 */
	private V deserialize(byte[] rawData, Object key)
	{
		V val;
		try {
			String file = key+".ser";
			FileInputStream fis = new FileInputStream(file);
		ObjectInputStream ois = new ObjectInputStream(fis);
			val=(V)ois.readObject();
			ois.close();
			return val;
		} catch (Exception e) {
			e.printStackTrace();
			return null;
		}
	}

/**
 * returns value V according to key in FileMap
 *
 * @return V
 *@param Object (key)
 */
	public V get(Object key) {
		try {
			byte[] buff = new byte[(int)map.get(key).getBuffSize()];
			raf.seek(map.get(key).getLocation());
			raf.read(buff);
			V val_to_return= this.deserialize(buff, key);
			return val_to_return;
		} catch (IOException e) {
			e.printStackTrace();
			return null;
		}
	}


/**
 * removes V from FileMap according to key and returns it
 *
 * @return V
 * @param Object (key)
 */
	public V remove(Object key) {
		V to_return= this.get(key);
		map.remove(key);
		return to_return;
	}

/**
 * returns a Set of the FileMap keys
 *
 * @return Set<K>
 */
	public Set<K> keySet() {
		return map.keySet();
	}

	@Override
/**
 * clears FileMap
 */
	public void clear() {
		map.clear();
		try {
			raf.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

/**
 * Action is not supported in FileMap, as it contradicts
 * the purpose of FileMap use.
 *
 * @throws UnsupportedOperationException
 */
	@Override
	public boolean containsValue(Object arg0) throws UnsupportedOperationException{
		UnsupportedOperationException e = new UnsupportedOperationException();
		throw e;
	}

/**
 * Action is not supported in FileMap, as it contradicts
 * the purpose of FileMap use.
 *
 *   @throws UnsupportedOperationException
 */
	@Override
	public Set<java.util.Map.Entry<K, V>> entrySet() throws UnsupportedOperationException{
		UnsupportedOperationException e = new UnsupportedOperationException();
		throw e;
	}

/**
 *checks if FileMap is empty. returns true or false.
 *
 * @return boolean
 */
	@Override
	public boolean isEmpty() {
		return map.isEmpty();
	}


/**
 * returns FileMap size
 *
 * @return int
 */
	@Override
	public int size() {
		return map.size();
	}

/**
 * puts all elements in parameter Map in FileMap
 *
 * @param Map<? extends K, ? extends V>
 */
	@Override
	public void putAll(Map<? extends K, ? extends V> arg0) {
		for(K index : arg0.keySet())
		{
			this.put(index, arg0.get(index));
		}
	}

/**
 * Action is not supported in FileMap, as it contradicts
 * the purpose of FileMap use.
 *
 * @throws UnsupportedOperationException
 */
	@Override
	public Collection<V> values() throws UnsupportedOperationException {
		UnsupportedOperationException e = new UnsupportedOperationException();
		throw e;
	}

	@Override
/**
 * checks if FileMap contains key. returns true or false
 *
 *@param Object
 *@returns boolean
 */
	public boolean containsKey(Object key) {
		return map.containsKey(key);
	}



	public static void main( String[] args )
     {
	 FileMap<Integer, SortedSet<String>> fm;
	 try
	 {
	 fm = new FileMap<Integer, SortedSet<String>>();
	 Scanner sc = new Scanner( new File( args[0] ) );
	 while( sc.hasNext() )
	 {
	 String word = sc.next();
	 Integer count = 0;
	 if( sc.hasNext() )
	 count = Integer.parseInt( sc.next() );
	 SortedSet<String> set = null;
	 if( !fm.containsKey( count ) )
	 	set = new TreeSet<String>();
	 else
	 	set = fm.get( count );
	 set.add( word );
	 fm.put( count, set );
	 }
	 for( Integer i : fm.keySet() )
	 {
	 System.out.print( i + ": " );
	 for( String s : fm.get( i ) )
	 System.out.print( s + ", " );
	 System.out.println();
	 }
	 sc.close();
	 }
	 catch( IOException e )
	 {
	 e.printStackTrace();
	 }
	 }


}
