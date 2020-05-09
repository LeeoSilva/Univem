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
    public class Truck : BaseVehicles
    {
        public Truck(int numberAxis, double tollPaymentBalance) : base(numberAxis, tollPaymentBalance, "Truck")
        {
        }
    }
}
