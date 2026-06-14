*This project has been created as part of the 42 curriculum by dnakamot.*

# ft_printf

## “Description”

`ft_printf` は、C標準ライブラリ関数 `ft_printf` を再実装したプロジェクトです。Cにおける可変長引数関数の仕組みを理解し、オリジナルの `ft_printf` のコアとなるフォーマット処理を自力で再現することを目的としています。

以下の変換指定子に対応しています：

| 指定子 | 説明 |
|--------|------|
| `%c` | 1文字 |
| `%s` | 文字列 |
| `%p` | ポインタアドレス（16進数） |
| `%d` / `%i` | 符号付き10進整数 |
| `%u` | 符号なし10進整数 |
| `%x` / `%X` | 符号なし16進整数（小文字/大文字） |
| `%%` | パーセント記号そのもの |

オリジナルの `ft_printf` と同様に、出力した文字数を返り値として返します。

## アルゴリズムとデータ構造

### アプローチ

本実装では、**ディスパッチテーブル**（関数ポインタの配列）を用いて、各フォーマット指定子を対応するハンドラ関数に紐付けています。`ft_printf` がフォーマット文字列中に `%` を検出すると、次の文字を読み取り、テーブルから対応するハンドラを即座に呼び出します。

この方式を採用した理由は以下のとおりです：

- **拡張性**: 新しい指定子を追加する際、既存のロジックを変更せずにハンドラを登録するだけで済む。
- **関心の分離**: 各変換処理が独立した関数として切り分けられており、読みやすく、テストや保守が容易。
- **明快さ**: 指定子と処理の対応関係が一箇所にまとまっており、コードの意図が明確。

`if-else` の連鎖や `switch` 文より保守性が高く、42の他のプロジェクトへの流用も想定して設計しました。

### 可変長引数

`<stdarg.h>` の `va_list`・`va_start`・`va_arg`・`va_end` を使って、`ft_printf` に渡された可変長引数を順番に取り出しています。各ハンドラは `va_list` をポインタで受け取り、引数を順次消費していきます。

### 使用データ構造

- **`va_list`**: 可変長引数リストを順番に走査するために使用。
- **関数ポインタ配列**: 指定子文字をハンドラ関数に O(1) でマッピングするために使用。

## “Instructions”

### コンパイル

リポジトリをクローンしてライブラリをビルドします：

```bash
git clone https://github.com/dnakamot/ft_printf.git
cd ft_printf
make
```

### 使用方法
```c
int main(void)
{
    char str[]="mojiretu";

    ft_printf("%d",str);
}
```

ビルドが成功すると `libftprintf.a` という静的ライブラリが生成されます。

### Makefileターゲット一覧

| ターゲット | 説明 |
|------------|------|
| `make` / `make all` | ライブラリをコンパイルする |
| `make clean` | オブジェクトファイルを削除する |
| `make fclean` | オブジェクトファイルとライブラリを削除する |
| `make re` | すべてを削除して再ビルドする |

## “Resources”

### ドキュメント・リファレンス

- [cppreference — ft_printf（英語）](https://en.cppreference.com/w/c/io/fprintf) — `ft_printf` のフォーマット指定子と動作の公式リファレンス。
- [cppreference — 可変長引数関数（英語）](https://en.cppreference.com/w/c/variadic) — `va_list`・`va_start`・`va_arg`・`va_end` のリファレンス。
- [GNU Cライブラリマニュアル — Formatted Output（英語）](https://www.gnu.org/software/libc/manual/html_node/Formatted-Output.html) — glibcにおける `ft_printf` の実装に関する詳細な解説。
- [42 公式Subject PDF](https://cdn.intra.42.fr/pdf/pdf/96586/en.subject.pdf) — プロジェクトの課題PDF。

### AIの使用について

本プロジェクトでは、AI（Anthropic社のClaude）を以下の用途で使用しました：

- **デバッグの補助**: `va_arg` の型昇格ルール（`char` や `short` が `int` として渡される理由など）の挙動を理解するための質問。
- **エッジケースの確認**: `%s` に `NULL` を渡した場合や `%u` に負の値を渡した場合などの動作確認。
- **ドキュメント作成**: このREADMEの日本語文章の作成補助と技術的な説明の整理。

コア実装のコードはすべて自分で記述・理解したものであり、AIによるコード生成は行っていません。