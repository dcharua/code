import java.util.HashSet;
import java.util.Optional;
import java.util.Queue;
import java.util.Set;
import java.util.stream.Collectors;

public class DFA<T> {
    private Set<T> alphabet = new HashSet<T>();
    private Set<State> states = new HashSet<State>();
    private Set<Transition<T>> transitionFunction = new HashSet<Transition<T>>();

    public void addToAlphabet(T symbol) {
        alphabet.add(symbol);
    }

    public void removeFromAlphabet(T symbol){
        alphabet.remove(symbol);
    }

    public void addToStates(State state){
        states.add(state);
    }

    public void removeToState(State state){
        states.remove(state);
    }

    public void removeTransition(Transition<T> transition){
        transitionFunction.remove(transition);
    }

    public void addTransition(Transition<T> transition) throws IllegalArgumentException{
        // no 2 outputs for same input+symbol
        if(transitionFunction.stream()
                .noneMatch(t -> t.getInputState().equals(transition.getInputState()) &&
                                t.getSymbol().equals(transition.getSymbol()))){
            transitionFunction.add(transition);
        } else {
            throw new IllegalArgumentException();
        }
    }

    public Set<State> getAcceptStates(){
        return states.stream().filter(s -> s.isAcceptState())
                .collect(Collectors.toSet());
    }

    public State calculateFinalState(State state, Queue<T> symbol){
        if(symbol.isEmpty() && state.isFinalState()){
            return state;
        }
        Optional<State> nextState = getNextState(state, symbol.poll());
        if(nextState.isPresent()){
            return calculateFinalState(nextState.get(), symbol);
        }
        return state;
    }

    private Optional<State> getNextState(State state, T alphabet){
        return
                transitionFunction.stream()
                    .filter(t -> t.getInputState().equals(state) &&
                                 t.getSymbol().equals(alphabet))
                                    .map(t -> t.getOutputState()).findFirst();
    }
}
