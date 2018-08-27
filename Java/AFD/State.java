public class State {
    private boolean finalState = false;
    private boolean acceptState = false;

    public boolean isFinalState() {
        return finalState;
    }
    public void setFinalState(boolean finalState) {
        this.finalState = finalState;
    }
    public boolean isAcceptState() {
        return acceptState;
    }
    public void setAcceptState(boolean acceptState) {
        this.acceptState = acceptState;
    }
}
