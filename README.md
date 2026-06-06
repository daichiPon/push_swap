# push_swap

## ファイル構成

```
push_swap/
├── Makefile
├── README.md
├── includes/
│   └── push_swap.h      # 構造体・関数プロトタイプ
├── srcs/
│   ├── main.c           # エントリーポイント・引数解析
│   ├── error.c          # エラー処理
│   ├── stack_init.c     # スタックの初期化
│   ├── operations/
│   │   ├── op_swap.c    # sa, sb, ss
│   │   ├── op_push.c    # pa, pb
│   │   └── op_rotate.c  # ra, rb, rr, rra, rrb, rrr
│   ├── algorithms/
│   │   ├── simple.c     # O(n²)
│   │   ├── medium.c     # O(n√n)
│   │   ├── complex.c    # O(n log n)
│   │   └── adaptive.c   # 無秩序度で自動選択
│   └── utils/
│       ├── disorder.c   # 無秩序度の計算
│       └── bench.c      # --benchモード
```
