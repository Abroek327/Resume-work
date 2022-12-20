//in swift all classes and functions are public by default and passed by reference 

class oopType
{
    //declare variables
    var iNum:Int=0
    var fNum:Float=0.0
    var dNum:Double=0.0
    var inWord:String=""
    var boolVal:Bool=false
    var optionInt:Int?=0
    var arrval:[Int]=[]
    var dictVal: [String : Int] = [:]
    

    
    
    //initialize variables
    init()
    {
        iNum=1
        fNum=3.14
        dNum=3.141592630
        inWord="Hello World"
        boolVal=true
        optionInt=1
        arrval=[1,2,3,4,5]
        dictVal=["one":1,"two":2,"three":3]
        
    }
    
    func printVals()
    {
        print("iNum=\(iNum)")
        print("fNum=\(fNum)")
        print("dNum=\(dNum)")
        print("inWord=\(inWord)")
        print("boolVal=\(boolVal)")
        print("optionInt=\(optionInt)")
        print("arrval=\(arrval)")
        print("dictVal=\(dictVal)")
    }
   
    
    
}
let ex: oopType=gui()
 ex.printVals()