let _ =
  let answer (a : int) =
  if a mod 4 == 0 && (a mod 100 != 0 || a mod 400 == 0) then
    Format.printf "1" else
    Format.printf "0" in
    Scanf.scanf "%d" answer