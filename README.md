# Project structure and run guide

This document explains the repository layout, the main entry points, essential functions, and quick run instructions so a developer can get started quickly.

**Overview**
- Purpose: multimodal RAG (Retrieval-Augmented Generation) utilities and demo scripts built around LightRAG + RAG-Anything helpers.
- Main demo/entry script: `multimodal_rag_app.py` (demo application that initializes LightRAG, inserts sample content, and runs queries).

**Top-level files & folders**
- `multimodal_rag_app.py`: Primary demo script (entry point used in this workspace). Initializes LightRAG, inserts content (demo or parsed files), and runs queries.
- `README.md`, `README_zh.md`: Project READMEs with general info.
- `requirements.txt`: Pip requirements for runtime packages.
- `setup.py`, `pyproject.toml`: Packaging and project metadata.
- `raganything/`: Core library code for RAG-Anything wrappers and utilities.
- `rag_storage/`: Runtime storage used by LightRAG (vector DB, graph, caches). Created at runtime.
- `examples/`: Useful example scripts demonstrating different flows (parsing + RAG pipeline, insert content list, LMStudio integration, etc.).
- `test_installation.py`: Simple installation checks.

**Key modules inside `raganything/`**
- `raganything.py`:
  - `RAGAnything` class: High-level orchestration. Combines parsing, processing, insertion, and query flows.
  - `_ensure_lightrag_initialized()`: Ensures LightRAG instance and storages are ready.

- `processor.py`:
  - `process_document_complete(...)`: Full-document parsing + processing pipeline.
  - `process_document_complete_lightrag_api(...)`: Alternative flow using LightRAG APIs.
  - `insert_content_list(...)`: Insert pre-built content blocks directly (bypasses parsers).

- `query.py`:
  - `aquery(...)` / `query(...)`: Asynchronous and synchronous query interfaces.
  - Multimodal query helpers (image handling, VLM flows).

- `parser.py`:
  - Parsers and helpers that wrap external tools (MinerU, Docling). These may require external non-Python dependencies.

- `modalprocessors.py`:
  - Modal processors for images, tables, equations, and generic multimodal extraction.

- `utils.py`:
  - Helper utilities for insertion, formatting, and content transformations.

**Entry points & recommended workflow**
1. Demo quick-start (no external parsers):
   - `multimodal_rag_app.py` contains a self-contained demo that inserts sample content and runs queries.
   - This file was adapted to initialize LightRAG directly and insert content via `ainsert` / `insert_content_list` for portability.

2. Full parsing pipeline (requires external parser tools):
   - Use `examples/raganything_example.py` or call `RAGAnything.process_document_complete()`.
   - Note: MinerU/Docling parsers may require installing external packages or system tools (see parser logs and README).

**How to run (Windows PowerShell)**
1. Create & activate the virtual environment (if not already):
   - python -m venv venv
   - & "./venv/Scripts/Activate.ps1"

2. Install Python dependencies:
   - pip install -r requirements.txt
   - Optionally install extras or specific parsers: `pip install 'mineru[core]'` or `pip install docling` (only if you plan to use those parsers).

3. Set environment variables (preferred) or create a `.env` file in repo root:
   - In PowerShell: `$env:OPENAI_API_KEY = "<YOUR_API_KEY>"`
   - Or create a `.env` file containing: `OPENAI_API_KEY=your_key_here`

4. Run the demo entry script:
   - Simple (uses `py` launcher): `py multimodal_rag_app.py`
   - Or with venv python: `& './venv/Scripts/python.exe' multimodal_rag_app.py`

**Notes and troubleshooting**
- If you see parser-related errors (e.g., MinerU / Docling missing), either install the parser or use the demo which inserts sample content (no parser required).
- Storage is written to `./rag_storage` by default. Remove or back up this folder if you need a clean run.
- If you get OpenAI API errors, ensure `OPENAI_API_KEY` is set and the model you use supports the requested features (structured outputs, response_format).

**Examples to try**
- `examples/insert_content_list_example.py` — demonstrates `insert_content_list` usage.
- `examples/raganything_example.py` — full pipeline example (requires parser tools and OpenAI keys).

If you want, I can also:
- Add a short script to automate venv creation + install + run.
- Update the main `README.md` to include these instructions.

File created: [structure_readme.md](structure_readme.md)
