public class friends{
    private String _name;
    private String _job;
    private String _catchyPhrase;
    private int _apartmentNumber;

    public static int totalCharacters=0;
    public friends(String name){
        _name = name;
    }
    public friends(String name,String job,String phrase,int apartmentNumber){
        _name  =name;
        _job= job;
        _catchyPhrase = phrase;
        _apartmentNumber = apartmentNumber;
        totalCharacters++;
    }

    public String getName(){
        return _name;
    }
    public String getJob(){
        return _job;
    }
    public void setJob(String name){
        _name = name;
    }
    public void setApartmentNumber(int aparmentNumber){
        if(aparmentNumber>0){
            _apartmentNumber = aparmentNumber;
        }
        else{
            IO.println("apartment number should be positive");

        }

    }
    public String getCatchyPhrase(){
        return _catchyPhrase;
    }
    public void setCatchyPhrase(String phrase){
        _catchyPhrase = phrase;
    }

    
    @Override

    public String toString(){
        return "Name: " + _name + 
               "\nJob: " + _job + 
               "\nPhrase: " + _catchyPhrase + 
               "\nApt No: " + _apartmentNumber + 
               "\n--------------------";

    }
    




}
