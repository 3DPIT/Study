namespace AddTest;

public class Template2
{
    private int[] _numbers;
    public Template2(int[] numbers)
    {
        _numbers = numbers;
    }
    public int Result(Func<int,int,int> operator1)
    {
        int sumResult =0;
        for(int i=0 ; i<_numbers.Length;i++){
            sumResult=operator1(sumResult,_numbers[i]);
        }
        return sumResult;
    }
}