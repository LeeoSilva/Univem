/*
|--------------------------------------------------------------------------
| Integrantes    
|--------------------------------------------------------------------------
| 
| - Aron Camossi - 589977
| - Leonardo Silva - 591149
| - Joao Tramontini - 588466
*/

using Exercicio_20_05_09_OA.Domain.Entities;

namespace Exercicio_20_05_09_OA.Domain.Services
{
    public class TollCabin
    {
        public TollCabin(double tollValuePerAxis)
        {
            TollValuePerAxis = tollValuePerAxis;
            TotalValueCabin = 0;
        }

        private double TollValuePerAxis { get; set; }
        private double TotalValueCabin { get; set; }
    
    
        public bool AddVehiclesPass(BaseVehicles baseVehicle){
            double totalValue = GetNewValueByInstance(
                baseVehicle, FormatterValueAxis(baseVehicle.GetNumberAxis()));

            bool result = baseVehicle.SubTollPaymentBalance(totalValue);
            
            if(result)
                TotalValueCabin += totalValue;

            return result;
        }

        private double FormatterValueAxis(int numberAxis){
            return TollValuePerAxis * numberAxis;
        }

        private double GetNewValueByInstance(BaseVehicles baseVehicle, double totalValueAxis){
            if(baseVehicle is Motorcycle) return totalValueAxis * 0.5;
            else if(baseVehicle is Car) return totalValueAxis * 1;
            else if(baseVehicle is Truck) return totalValueAxis * 2;
            else return 0;
        }

        public string GetTollCabin(){
            return $"Valor do pedágio por eixo: {TollValuePerAxis}\n"
                    + $"Valor total da cabine: {TotalValueCabin}";
        }
    }
}
