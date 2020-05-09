/*
|--------------------------------------------------------------------------
| Integrantes    
|--------------------------------------------------------------------------
| 
| - Aron Camossi - 589977
| - Leonardo Silva - 591149
| - Joao Tramontini - 588466
*/


using System;
using Exercicio_20_05_09_OA.Domain.Entities;
using Exercicio_20_05_09_OA.Domain.Services;

namespace Exercicio_20_05_09_OA
{
    class Program
    {
        static void Main(string[] args)
        {
            int indexBaseVehicles = 0, indexTollCabin = 0;
            bool condicaoWhile = true;
            BaseVehicles[] baseVehicles = new BaseVehicles[GetNumberByArg("veículos")];
            TollCabin[] tollCabin = new TollCabin[GetNumberByArg("cabines do pedágio")];

            while(condicaoWhile){
                switch (Menu())
                {
                    case 1:
                        Console.Clear();
                        if(AddBaseVehicles()){
                            baseVehicles[indexBaseVehicles] = new Car(GetNumberAxis(), GetTollPaymentBalance());
                            Console.WriteLine(ReturnMessage.SucessAddVehicle);   
                            indexBaseVehicles++;
                        } else  
                            Console.WriteLine(ReturnMessage.NoMoreRoom);   
                        Console.ReadKey();
                        break;
                    case 2:
                        Console.Clear();
                        if(AddBaseVehicles()){
                            baseVehicles[indexBaseVehicles] = new Truck(GetNumberAxis(), GetTollPaymentBalance());
                            Console.WriteLine(ReturnMessage.SucessAddVehicle); 
                            indexBaseVehicles++;  
                        } else  
                            Console.WriteLine(ReturnMessage.NoMoreRoom);
                        Console.ReadKey();
                        break;
                    case 3:
                        Console.Clear();
                        if(AddBaseVehicles()){ 
                            baseVehicles[indexBaseVehicles] = new Motorcycle(GetNumberAxis(), GetTollPaymentBalance());
                            Console.WriteLine(ReturnMessage.SucessAddVehicle); 
                            indexBaseVehicles++;                          
                        } else  
                            Console.WriteLine(ReturnMessage.NoMoreRoom);
                        Console.ReadKey();
                        break;
                    case 4:
                        Console.Clear();
                        if(indexTollCabin < tollCabin.Length){
                            Console.Write("Digite qual o valor do pedágio por eixo:\t");
                            double tollValuePerAxis = Double.Parse(Console.ReadLine()); 
                            tollCabin[indexTollCabin] = new TollCabin(tollValuePerAxis);
                            Console.WriteLine(ReturnMessage.SucessAddVehicle);  
                            indexTollCabin++;
                        } else   
                            Console.WriteLine(ReturnMessage.NoMoreRoom);
                        Console.ReadKey();
                        break;
                    case 5:
                        Console.Clear();
                        if(indexBaseVehicles > 0){
                            GetListBaseVehicle();
                        } else
                            Console.WriteLine(ReturnMessage.EmptyList);
                        Console.ReadKey();
                        break;
                    case 6:
                        Console.Clear();
                        if(indexTollCabin > 0){
                            GetListTollCabin();
                        } else
                            Console.WriteLine(ReturnMessage.EmptyList);
                        Console.ReadKey();
                        break;
                    case 7:
                        Console.Clear();
                        if(indexBaseVehicles != 0 && indexTollCabin != 0){
                            GetListBaseVehicle();
                            Console.Write("Escolha um veículo:\t");
                            int numVehicle = Int32.Parse(Console.ReadLine()) - 1;
                            Console.Clear();
                            GetListTollCabin();
                            Console.Write("Escolha uma cabine:\t");
                            int numCabin = Int32.Parse(Console.ReadLine()) - 1;
                            if(tollCabin[numCabin].AddVehiclesPass(baseVehicles[numVehicle]))
                                Console.WriteLine(ReturnMessage.SuccessAddVehiclePass);
                            else
                                Console.WriteLine(ReturnMessage.ErrorAddVehiclePass);
                        } else
                            Console.WriteLine(ReturnMessage.SomeEmptyList);
                        Console.ReadKey();
                        break;
                    case 8:
                        Console.Clear();
                        Console.WriteLine(ReturnMessage.ExitProgram);
                        condicaoWhile = false;
                        break;    
                    default:
                        Console.Clear();
                        Console.WriteLine(ReturnMessage.OptionInvalid);
                        Console.ReadKey();
                        break;
                }
            }

            int Menu(){
                Console.Clear();
                Console.Write("[1] - Criar Automóvel\n[2] - Criar Caminhão\n"
                    + "[3] - Criar Motocicleta\n[4] - Criar Cabine Pedágio\n"
                    + "[5] - Listar Automóveis\n[6] - Listar Cabines Pedágio\n"
                    + "[7] - Passar Veículo\n[8] - Sair\n\nDigite um opção:\t");
                return Int32.Parse(Console.ReadLine());
            }

            int GetNumberByArg(string arg){
                Console.Clear();
                Console.Write($"Digite o número de {arg}:\t");
                return Int32.Parse(Console.ReadLine());
            }

            bool AddBaseVehicles(){
                if(indexBaseVehicles < baseVehicles.Length)
                    return true;
                
                return false;
            }

            int GetNumberAxis(){
                Console.Write("Digite o número de eixos para o automóvel:\t");
                return Int32.Parse(Console.ReadLine());
            }

            double GetTollPaymentBalance(){
                Console.Write("Digite o saldo para pagamento de pedágios:\t");
                return Double.Parse(Console.ReadLine());
            }

            void GetListBaseVehicle(){
                Console.WriteLine("Lista de Veículos:");
                Console.WriteLine("\n");
                for(int i = 0; i < indexBaseVehicles; i++){
                    Console.WriteLine($"[{i + 1}] - {baseVehicles[i].GetTypeName()}");
                    Console.WriteLine(baseVehicles[i].GetVehicle());
                    Console.WriteLine("\n");
                }
            }
            void GetListTollCabin(){
                Console.WriteLine("Lista de Cabines do Pedágio:");
                Console.WriteLine("\n");
                for(int i = 0; i < indexTollCabin; i++){
                    Console.WriteLine($"Cabine [{i + 1}]:");
                    Console.WriteLine(tollCabin[i].GetTollCabin());
                    Console.WriteLine("\n");
                }
            }

            
        }
    }
}
