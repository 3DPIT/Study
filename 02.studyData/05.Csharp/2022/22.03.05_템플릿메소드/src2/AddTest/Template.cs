namespace AddTest;

public abstract class Template
{
    private int[] _numbers;
    public Template(int[] numbers)
    {
        _numbers = numbers;
    }
    public int Result()
    {
        int sumResult =0;
        for(int i=0 ; i<_numbers.Length;i++){
            sumResult=getResult(sumResult,_numbers[i]);
        }
        return sumResult;
    }
   protected abstract int getResult(int sumResult, int number);
}