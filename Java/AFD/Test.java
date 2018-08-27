import java.util.*;


public class Test{
  public static void main(String[] args){
       DFA<Integer> dfa = new DFA<Integer>();
       dfa.addToAlphabet(0);
       dfa.addToAlphabet(1);
       // first state
       State evenNumber = new State();
       evenNumber.setFinalState(true);
       evenNumber.setAcceptState(true);
       dfa.addToStates(evenNumber);
       // second state
       State oddNumber = new State();
       oddNumber.setFinalState(true);
       dfa.addToStates(oddNumber);
       //  transitions
       Transition<Integer> t1 =
               new Transition<Integer>(evenNumber, 0, oddNumber);
       dfa.addTransition(t1);
       Transition<Integer> t2 =
               new Transition<Integer>(oddNumber, 0, evenNumber);
       dfa.addTransition(t2);
       Transition<Integer> t3 =
               new Transition<Integer>(evenNumber, 1, evenNumber);
       dfa.addTransition(t3);
       Transition<Integer> t4 =
               new Transition<Integer>(oddNumber, 1, oddNumber);
       dfa.addTransition(t4);
       // compute
       LinkedList<Integer> binaryList =
               new LinkedList<Integer>();
       binaryList.add(1);
       binaryList.add(0);
       binaryList.add(1);
       binaryList.add(1);
       binaryList.add(0);
       System.out.println(dfa.calculateFinalState(evenNumber, binaryList));
   }
 }
