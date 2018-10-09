//After draw a histogram
TPaveStats *st = ((TPaveStats *)(gPad->GetPrimitive("stats")));
  st->SetY1NDC(st->GetY1NDC() - 0.7);
  st->SetY2NDC(st->GetY2NDC() - 0.7);
