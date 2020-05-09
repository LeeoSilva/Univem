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
    public class Car : BaseVehicles
    {
        public Car(int numberAxis, double tollPaymentBalance) : base(numberAxis, tollPaymentBalance, "Car")
        {
        }
    }
}
