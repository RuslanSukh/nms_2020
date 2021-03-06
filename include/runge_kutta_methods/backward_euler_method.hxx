#ifndef BACKWARD_EULER_METHOD_HXX_INCLUDED
#define BACKWARD_EULER_METHOD_HXX_INCLUDED

#include "runge_kutta_method.hxx"
#include "runge_kutta_method_impl.hxx"

namespace Math_structures
{

template<
    typename T_arg_u = double,
    typename T_arg_t = double
    >
class Backward_Euler_method
    :   public Runge_Kutta_method_impl<1, T_arg_u, T_arg_t>
{
public:

    constexpr Backward_Euler_method() noexcept
        :   Runge_Kutta_method_impl<1, T_arg_u, T_arg_t>{
                    {1}, {
                        {{
                            {{1.0}}
                        }},
                        {{1.0}},
                        {{1.0}}
                    }}
    { }

    constexpr Backward_Euler_method
        (const Backward_Euler_method<T_arg_u, T_arg_t>&) noexcept = default;

    constexpr Backward_Euler_method
        (Backward_Euler_method<T_arg_u, T_arg_t>&&) noexcept = default;

    virtual ~Backward_Euler_method() noexcept = default;

    constexpr Backward_Euler_method<T_arg_u, T_arg_t>&
        operator=(const Backward_Euler_method<T_arg_u, T_arg_t>&) noexcept = default;

    constexpr Backward_Euler_method<T_arg_u, T_arg_t>&
        operator=(Backward_Euler_method<T_arg_u, T_arg_t>&&) noexcept = default;

    virtual int get_accuracy_order() const noexcept override
    {
        return One_step_ODE_solver<T_arg_u, T_arg_t>
               ::get_accuracy_order();
    }

    virtual T_arg_u get_solution(const std::function<T_arg_u(T_arg_u, T_arg_t)>& f_rhs,
                                 const T_arg_u& u_prev, const T_arg_t& t, const T_arg_t& dt) override
    {
        return this->get_u_next(f_rhs, u_prev, t, dt);
    }

};

}

#endif // BACKWARD_EULER_METHOD_HXX_INCLUDED
