package br.mackenzie.mackplay;

public abstract class Jogador extends Usuario {
    
    String alias;
    double score;
    Participacao participacao[];
    int countParticipacao = 0;
    
    public Jogador() {
        super.setNome("Macke Junior");
        this.alias = "The Junior";
        super.setLogin("mack@mackenzie.com.br");
        this.participacao = new Participacao[200];
    }
    
    public Jogador(String alias, String nome, String login) {
        this.alias = alias;
        super.setNome(nome);
        super.setLogin(login);
        this.participacao = new Participacao[200];
    }
    
    public void setAlias(String alias) {
        this.alias = alias;
    }
    
    public String getAlias() {
        return this.alias;
    }   
    
    public void setScore(double score) {
        this.score = score;
    }
    
    public double getScore() {
        return this.score;
    }
    
    public int getNumParticipacoes() {
        int numParticipacoes = 0;
        for (int i = 0; i < this.participacao.length; i++) {
            if (this.participacao[i] != null) {
                numParticipacoes++;
            }
        }
        
        return numParticipacoes;
    }
    
    public Participacao[] getParticipacoes() {
        return this.participacao;
    }
    
    public void addParticipacoes(Participacao participacao) {
        this.participacao[countParticipacao] = participacao;
        countParticipacao++;
    }
}
