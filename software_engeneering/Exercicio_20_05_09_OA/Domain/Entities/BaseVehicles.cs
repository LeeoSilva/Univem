/*
|--------------------------------------------------------------------------
| Integrantes    
|--------------------------------------------------------------------------
| 
| - Aron Camossi - 589977
| - Leonardo Silva - 591149
| - Joao Tramontini - 588466
*/

namespace Exercicio_20_05_09_OA.Domain.Entities
{
    public class BaseVehicles
    {
        public BaseVehicles(int numberAxis, double tollPaymentBalance, string typeName)
        {
            NumberAxis = numberAxis;
            TollPaymentBalance = tollPaymentBalance;
            TypeName = typeName;
        }

        private string TypeName { get; set; }
        private int NumberAxis { get; set; }
        private double TollPaymentBalance { get; set; }

        public bool SubTollPaymentBalance(double value){
            bool result = (TollPaymentBalance - value) >= 0;

            if(result)
                TollPaymentBalance -= value;
            
            return result;
        }

        public int GetNumberAxis(){
            return NumberAxis;
        }

        public string GetVehicle(){
            return $"Numero de eixos: {NumberAxis}\n"
                    + $"Saldo para pagamento de pedágios: {TollPaymentBalance}";
        }

        public string GetTypeName(){
            return TypeName;
        }
    }
}
