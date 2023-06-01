using System;
using System.IO;

class Program{
    static byte ConvertHex(string str){
        if(str.Split('x').Length == 2)
            return Convert.ToByte(Convert.ToInt32(str, 16));
        return Convert.ToByte(str);
    }
    public static void Main(string[] args){
        List<byte> bytes = new();
        if(args.Length < 1){
            Console.WriteLine("No file selected!");
            Environment.Exit(-1);
        }
        string filename = args[0];
        string output = "program.bin";
        if(args.Length > 1){
            output = args[1];
        }
        if(!File.Exists(filename)){
            Console.WriteLine("File does not exist!");
            Environment.Exit(-1);
        }
        string[] lines = File.ReadAllLines(filename);
        foreach(string line in lines){
            if(line == String.Empty || line[0] == ';')
                continue;
            string[] parts = line.Split(' ');
            switch(parts[0]){
                case "mov":
                    bytes.Add(1);
                    bytes.Add(ConvertHex(parts[1]));
                    bytes.Add(ConvertHex(parts[2]));
                    break;
                case "cpy":
                    bytes.Add(2);
                    bytes.Add(ConvertHex(parts[1]));
                    bytes.Add(ConvertHex(parts[2]));
                    break;
                case "exit":
                    bytes.Add(3);
                    break;
                case "print":
                    bytes.Add(4);
                    break;
                case "read":
                    bytes.Add(5);
                    break;
                case "add":
                    bytes.Add(6);
                    bytes.Add(ConvertHex(parts[1]));
                    bytes.Add(ConvertHex(parts[2]));
                    break;
                case "sub":
                    bytes.Add(7);
                    bytes.Add(ConvertHex(parts[1]));
                    bytes.Add(ConvertHex(parts[2]));
                    break;
                case "jmp":
                    bytes.Add(8);
                    bytes.Add(ConvertHex(parts[1]));
                    break;
                case "dw":
                    bytes.Add(ConvertHex(parts[1]));
                    break;
                case "jnz":
                    bytes.Add(14);
                    bytes.Add(ConvertHex(parts[1]));
                    break;
                case "jne":
                    bytes.Add(13);
                    bytes.Add(ConvertHex(parts[1]));
                    break;
                case "je":
                    bytes.Add(12);
                    bytes.Add(ConvertHex(parts[1]));
                    break;
                default:
                    bytes.Add(0);
                    break;
            }
            FileStream fs = File.OpenWrite(output);
            fs.Write(bytes.ToArray(),0,bytes.Count);
            fs.Close();
        }
    }
}